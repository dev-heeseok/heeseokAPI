#pragma once

#include "AddionalDatabase.h"

template <typename TYPE>
class MSegment
{
public:
	typedef struct tagMITEM
	{
		MPARAM param;
		TYPE data;

		tagMITEM* hprev; // previous for hash
		tagMITEM* hnext; // next for hash
		tagMITEM* lprev; // previous for list
		tagMITEM* lnext; // next for list

		tagMITEM() : hprev(NULL), hnext(NULL), lprev(NULL), lnext(NULL)
		{}

	} MITEM, * LPMITEM;

public:
	MSegment()
		: m_nMinimum(0), m_nMaximum(0)
		, m_nHashSize(DEFAULT_HASH_SIZE), m_nDataSize(0)
		, m_pHead(NULL), m_pTail(NULL), m_pHashMap(NULL)
	{
		m_pHashMap = new LPMITEM[m_nHashSize];
		memset(m_pHashMap, 0, sizeof(LPMITEM) * m_nHashSize);
	}
	MSegment(int nHashSize)
		: m_nMinimum(0), m_nMaximum(0)
		, m_nHashSize(nHashSize), m_nDataSize(0)
		, m_pHead(NULL), m_pTail(NULL), m_pHashMap(NULL)
	{
		m_pHashMap = new LPMITEM[m_nHashSize];
		memset(m_pHashMap, 0, sizeof(LPMITEM) * m_nHashSize);
	}
	~MSegment()
	{

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
		return NULL;
	}
	int GetKeyList(OUT MArrayK& aKey)
	{
		return 0;
	}
	int GetItrList(OUT MArrayITR& aKey)
	{
		return 0;
	}
	MITERATOR GetHeadPosition()
	{
		return NULL;
	}
	void Previous(OUT MITERATOR& itr)
	{

	}
	void Next(OUT MITERATOR& itr)
	{

	}
	const TYPE& GetAtNU(MITERATOR itr)
	{

	}
	MITERATOR InsertNU(const TYPE& data)
	{

	}
	BOOL SetAtNU(MITERATOR itr, const TYPE& data)
	{

	}
	BOOL Remove(MITERATOR itr)
	{

	}
	BOOL RemoveNext(OUT MITERATOR& itr)
	{

	}
	BOOL RemoveWithoutDelete(MITERATOR itr)
	{

	}
	BOOL RemoveNextWithoutDelete(OUT MITERATOR& itr)
	{

	}
	void ResizeHash(int nHashSize)
	{

	}
	void RemakeHash()
	{

	}
	MKEY MaximumKey()
	{

	}
	MKEY MinimumKey()
	{

	}
	MKEY NewKey()
	{

	}

protected:
	MKEY m_nMinimum;
	MKEY m_nMaximum;

	int m_nHashSize;
	int m_nDataSize;
	LPMITEM m_pHead;
	LPMITEM m_pTail;
	LPMITEM* m_pHashMap;

};