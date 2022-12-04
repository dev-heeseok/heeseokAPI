#pragma once

#include "AddionalDatabase.h"

class MBlock;
class MTableSpace;
class AFX_EXT_CLASS MSchema
{
public:
	MSchema(MTableSpace* pTableSpace, UINT uiType);
	virtual ~MSchema();

public:
	virtual BOOL ProcessRelation() = 0;
	virtual void LazyDelete() = 0;

	virtual BOOL IsEmpty() const = 0;
	virtual int GetSize() const = 0;
	virtual int GetKeyList(OUT std::vector<MKEY>& aKey) = 0;
	virtual int GetItrList(OUT std::vector<MITERATOR>& aItr) = 0;

	virtual MITERATOR Find(MKEY key) const = 0;
	virtual MITERATOR InsertNU(MBlock* pData) = 0;
	virtual BOOL SetAtNU(MITERATOR itr, MBlock* pData) = 0;

public:
	UINT GetType() { return m_uiType; }
	UINT GetFlag() { return m_uiFlag; }
	void SetFlag(UINT uiFlag) { m_uiFlag = uiFlag; }

protected:
	MTableSpace* m_pTableSpace;
	UINT m_uiType;
	UINT m_uiFlag; // SchemaFlag

};