#pragma once

#include "AddionalDatabase.h"

class MTableSpace;
class AFX_EXT_CLASS MBlock
{
public:
	MBlock();
	virtual ~MBlock();

public:
	virtual MKEY GetPrimaryKey() const = 0;
	virtual void SetPrimaryKey(MKEY key) = 0;

	virtual BOOL ChmodFile(MTableSpace* pTableSpace) = 0;
	virtual BOOL ChmodMomory(MTableSpace* pTableSpace) = 0;


};
