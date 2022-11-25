#pragma once

#include "MDataBaseDefine.h"
#include <vector>

class MBlock;
class MTableSpace;
class AFX_EXT_CLASS MSegmentBase
{
public:
	MSegmentBase(MTableSpace* pTableSpace, int nType);
	virtual ~MSegmentBase();

public:
	virtual int GetDataType() { return m_nDataType; }
	virtual int GetFlag() { return m_nFlag; }
	virtual void SetFlag(int nFlag) { m_nFlag = nFlag; }

public:
	virtual BOOL IsEmpty() const = 0;
	virtual int GetSize() const = 0;
	virtual int GetKeyList(OUT std::vector<MKEY>& aKey) = 0;
	virtual int GetItrList(OUT std::vector<MITERATOR>& aItr) = 0;

	virtual MITERATOR Find(MKEY key) const = 0;
	virtual MITERATOR InsertNU(MBlock* pData) = 0;
	virtual BOOL SetAtNU(MITERATOR itr, MBlock* pData) = 0;

protected:
	MTableSpace* m_pTableSpace;
	int m_nDataType;
	int m_nFlag;

};