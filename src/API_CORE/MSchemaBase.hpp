#pragma once

#include "AddionalDatabase.h"

#include "MSchema.h"
#include "MSegment.hpp"

class MTableSpace;

template <typename TYPE>
class MSchemaBase : public MSchema
{
public:
	MSchemaBase(MTableSpace* pTableSpace, UINT uiType, int nHashSize)
		: MSchema(pTableSpace, uiType), m_segment(nHashSize)
	{}
	virtual ~MSchemaBase()
	{}

public:
	virtual BOOL ProcessRelation() override
	{
		return TRUE;
	}
	virtual void LazyDelete() override final
	{

	}

	virtual BOOL IsEmpty() const override
	{
		return FALSE;
	}
	virtual int GetSize() const override
	{
		return 0;
	}
	virtual int GetKeyList(OUT std::vector<MKEY>& aKey) override
	{
		return 0;
	}
	virtual int GetItrList(OUT std::vector<MITERATOR>& aItr) override
	{
		return 0;
	}
	virtual MITERATOR Find(MKEY key) const override
	{
		return NULL;
	}
	virtual MITERATOR InsertNU(MBlock* pData) override
	{
		return NULL;
	}
	virtual BOOL SetAtNU(MITERATOR itr, MBlock* pData) override
	{
		return FALSE;
	}

protected:
	MSegment<TYPE> m_segment;

};