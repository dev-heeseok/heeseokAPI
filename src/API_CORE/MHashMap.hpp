#pragma once

#include <memory>
#include <unordered_map>
#include "MDataBaseDefine.h"

template <typename T>
class MHashMap
{
	struct tagBucket
	{

	};

	using BUCKET_PTR = std::shared_ptr<tagBucket>;

public:
	MHashMap()
		: m_nMinKey(0), m_nMaxKey(0)
		, m_nDataSize(0), m_nHashSize(0)
		, m_pHead(nullptr), m_pTail(nullptr)
		, m_pHashTable(nullptr)
	{

	}
	~MHashMap()
	{

	}

public:
	MITERATOR InsertNU(const T& data)
	{
		MKEY key = data.GetKey();

		if (!IS_VALID(key)) 
		{ 
			ASSERT(FALSE);
			return MITERATOR(nullptr);
		}


	}

	MITERATOR Find(MKEY key) const
	{
		if (!IS_VALID(key))
		{
			ASSERT(FALSE);
			return MITERATOR(nullptr);
		}


	}

protected:
	int m_nMinKey;
	int m_nMaxKey;

	int m_nDataSize;
	int m_nHashSize;
	tagBucket* m_pHead;
	tagBucket* m_pTail;
	tagBucket* m_pHashTable;

};