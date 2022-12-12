#pragma once

#include "AddionalDatabase.h"

template <typename TYPE>
class MSegment
{
public:
	struct tagMData
	{
		MPARAM param;
		TYPE data;

		tagMData* hprev; // previous for hash
		tagMData* hnext; // next for hash
		tagMData* lprev; // previous for list
		tagMData* lnext; // next for list

		tagMData() : hprev(NULL), hnext(NULL), lprev(NULL), lnext(NULL)
		{}

	};

	using MDATA = tagMData;
	using LPMDATA = MDATA*;

public:
	MSegment()
		: m_nMinimum(0), m_nMaximum(0)
		, m_nHashSize(DEFAULT_HASH_SIZE), m_nDataSize(0)
		, m_pHead(NULL), m_pTail(NULL), m_pHashMap(NULL)
	{
		m_pHashMap = new LPMDATA[m_nHashSize];
		memset(m_pHashMap, 0, sizeof(LPMDATA) * m_nHashSize);
	}
	MSegment(int nHashSize)
		: m_nMinimum(0), m_nMaximum(0)
		, m_nHashSize(nHashSize), m_nDataSize(0)
		, m_pHead(NULL), m_pTail(NULL), m_pHashMap(NULL)
	{
		m_pHashMap = new LPMDATA[m_nHashSize];
		memset(m_pHashMap, 0, sizeof(LPMDATA) * m_nHashSize);
	}
	~MSegment()
	{
		RemoveAll();

		ReleaseHash();
	}

public:
	BOOL IsEmpty() const
	{
		return m_nDataSize == 0;
	}
	int GetSize() const
	{
		return m_nDataSize;
	}
	MITERATOR Find(MKEY key) const
	{
		if (!IS_VALID(key)) return NULL;

		int idx = HASH_INDEX(key, m_nHashSize);

		MDATA* lpData = m_pHashMap[idx];
		while (lpData)
		{
			if (lpData->data.GetPrimaryKey() == key)
				return reinterpret_cast<MITERATOR>(lpData);

			lpData = lpData->hnext;
		}

		return NULL;
	}
	int GetKeyList(OUT std::vector<MKEY>& aKey)
	{
		aKey.clear();

		if (m_nDataSize)
		{
			MDATA* lpData = m_pHead;
			while (lpData)
			{
				aKey.push_back(lpData->data.GetPrimaryKey());
				lpData = lpData->lnext;
			}
		}

		return m_nDataSize;
	}
	int GetItrList(OUT std::vector<MITERATOR>& aItr)
	{
		aItr.clear();

		if (m_nDataSize)
		{
			MDATA* lpData = m_pHead;
			while (lpData)
			{
				aItr.push_back(reinterpret_cast<MITERATOR>(lpData));
				lpData = lpData->lnext;
			}
		}

		return m_nDataSize;
	}
	MITERATOR GetHeadPosition()
	{
		return reinterpret_cast<MITERATOR>(m_pHead);
	}
	void Previous(OUT MITERATOR& itr)
	{
		if (IS_VALID(itr))
			itr = reinterpret_cast<MITERATOR>(((MDATA*)itr)->lprev);
	}
	void Next(OUT MITERATOR& itr)
	{
		if (IS_VALID(itr))
			itr = reinterpret_cast<MITERATOR>(((MDATA*)itr)->lnext);
	}
	const TYPE& GetAtNU(MITERATOR itr)
	{
		return ((MDATA*)itr)->data;
	}
	MITERATOR InsertNU(const TYPE& data)
	{
		MKEY key = data.GetPrimaryKey();

		if (!IS_VALID(key)) { ASSERT(FALSE); return NULL; }
		if (Find(key)) { ASSERT(FALSE); return NULL; }

		MDATA* lpNewData = new MDATA;
		lpNewData->data = data;

		InsertHash(lpNewData);
		InsertData(lpNewData);

		KeyScaling(key);
		m_nDataSize++;

		return reinterpret_cast<MITERATOR>(lpNewData);
	}
	BOOL SetAtNU(MITERATOR itr, const TYPE& data)
	{
		MKEY nKey = data.GetPrimaryKey();

		if (!IS_VALID(itr)) { ASSERT(FALSE); return FALSE; }
		if (!IS_VALID(nKey)) { ASSERT(FALSE); return FALSE; }

		MKEY nOrgKey = ((MDATA*)itr)->data.GetPrimaryKey();
		if (nOrgKey != nKey)
		{
			MITERATOR itrFind = Find(nKey);

			if (IS_VALID(itrFind)) { ASSERT(FALSE); return FALSE; }

			MDATA* lpData = (MDATA*)itr;
			EraseHash(lpData);
			lpData->data = data;
			InsertHash(lpData);
			KeyScaling(nKey);
		}
		else
		{
			((MDATA*)itr)->data = data;
		}

		return TRUE;
	}
	BOOL Remove(MITERATOR itr)
	{
		if (!IS_VALID(itr)) { ASSERT(FALSE); return FALSE; }

		MDATA* lpData = (MDATA*)itr;

		EraseHash(lpData);
		EraseData(lpData);

		m_nDataSize--;
		SAFE_DELETE(lpData);

		return TRUE;
	}
	BOOL RemoveNext(OUT MITERATOR& itr)
	{
		if (!IS_VALID(itr)) { ASSERT(FALSE); return FALSE; }

		MDATA* lpData = (MDATA*)itr;

		EraseHash(lpData);
		EraseData(lpData);

		itr = reinterpret_cast<MITERATOR>(lpData->lnext);

		m_nDataSize--;
		SAFE_DELETE(lpData);

		return TRUE;
	}
	BOOL RemoveWithoutDelete(MITERATOR itr)
	{
		if (!IS_VALID(itr)) { ASSERT(FALSE); return FALSE; }

		MDATA* lpData = (MDATA*)itr;

		EraseHash(lpData);
		EraseData(lpData);

		m_nDataSize--;
		lpData->param.removed = PARAM_ON;

		return TRUE;
	}
	BOOL RemoveNextWithoutDelete(OUT MITERATOR& itr)
	{
		if (!IS_VALID(itr)) { ASSERT(FALSE); return FALSE; }

		MDATA* lpData = (MDATA*)itr;

		EraseHash(lpData);
		EraseData(lpData);

		itr = reinterpret_cast<MITERATOR>(lpData->lnext);

		m_nDataSize--;
		lpData->param.removed = PARAM_ON;

		return TRUE;
	}
	void ResizeHash(int nHashSize)
	{
		SAFE_DELETE_ARRAY(m_pHashMap);

		m_nHashSize = nHashSize;
		m_pHashMap = new LPMDATA[m_nHashSize];

		RemakeHash();
	}
	void RemakeHash()
	{
		memset(m_pHashMap, 0, sizeof(LPMDATA) * m_nHashSize);

		MDATA* lpData = m_pHead;
		while (lpData)
		{
			InsertHash(lpData);

			lpData = lpData->lnext;
		}
	}
	MKEY MaximumKey()
	{
		return m_nMaximum;
	}
	MKEY MinimumKey()
	{
		return m_nMinimum;
	}
	MKEY NewKey()
	{
		return MaximumKey() + 1;
	}

	void PushDel(MITERATOR itr)
	{
		m_deleter.push_back(itr);
	}
	void ReleaseDel()
	{
		if (m_deleter.empty()) return;

		for (auto itr : m_deleter)
		{
			MDATA* lpData = (MDATA*)itr;
			SAFE_DELETE(lpData);
		}

		m_deleter.clear();
	}

protected:
	void InsertHash(MDATA* lpData)
	{
		int idx = HASH_INDEX(lpData->data.GetPrimaryKey(), m_nHashSize);

		if (m_pHashMap[idx]) m_pHashMap[idx]->hprev = lpData;

		lpData->hprev = NULL;
		lpData->hnext = m_pHashMap[idx];

		m_pHashMap[idx] = lpData;
	}
	void EraseHash(MDATA* lpData)
	{
		int idx = HASH_INDEX(lpData->data.GetPrimaryKey(), m_nHashSize);

		if (lpData->hprev)
			lpData->hprev->hnext = lpData->hnext;
		else
			m_pHashMap[idx] = lpData->hnext;

		if (lpData->hnext)
			lpData->hnext->hprev = lpData->hprev;
	}
	void ReleaseHash()
	{
		SAFE_DELETE_ARRAY(m_pHashMap);
		m_nHashSize = 0;
	}
	void InsertData(MDATA* lpData)
	{
		if (m_pHead == NULL)
		{
			lpData->lprev = NULL;
			lpData->lnext = NULL;
			m_pHead = m_pTail = lpData;
		}
		else
		{
			if (m_pTail) m_pTail->lnext = lpData;

			lpData->lprev = m_pTail;
			lpData->lnext = NULL;
			m_pTail = lpData;
		}
	}
	void EraseData(MDATA* lpData)
	{
		if (lpData->lprev) lpData->lprev->lnext = lpData->lnext;
		else m_pHead = lpData->lnext;

		if (lpData->lnext) lpData->lnext->lprev = lpData->lprev;
		else m_pTail = lpData->lprev;
	}
	void RemoveAll()
	{
		memset(m_pHashMap, 0, sizeof(LPMDATA) * m_nDataSize);

		MDATA* lpNext = NULL;
		MDATA* lpData = m_pHead;
		while (lpData)
		{
			lpNext = lpData->lnext;
			SAFE_DELETE(lpData);
			lpData = lpNext;
		}

		m_nMinimum = m_nMaximum = 0;
		m_nDataSize = 0;
		m_pHead = m_pTail = NULL;
	}
	void KeyScaling(MKEY key)
	{
		if (m_nDataSize > 0)
		{
			m_nMinimum = key < m_nMinimum ? key : m_nMinimum;
			m_nMaximum = key > m_nMaximum ? key : m_nMaximum;
		}
		else
		{
			m_nMinimum = m_nMaximum = key;
		}
	}

protected:
	MKEY m_nMinimum;
	MKEY m_nMaximum;

	int m_nHashSize;
	int m_nDataSize;
	MDATA* m_pHead;
	MDATA* m_pTail;
	LPMDATA* m_pHashMap;

	std::vector<MITERATOR> m_deleter;
};