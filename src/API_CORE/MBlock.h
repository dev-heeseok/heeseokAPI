#pragma once

#include "AddionalProject.h"

//#pragma pack(push, 4)

class MTableSpace;
class MSegment;

class AFX_EXT_CLASS MBlock
{
public:
	MBlock();
	virtual ~MBlock();

public:
	virtual int GetDataType() = 0;
	virtual void Initialize() = 0;
	
	virtual BOOL ChmodRead(MSegment* pSegment) = 0;
	virtual BOOL ChmodWrite(MSegment* pSegment) = 0;

};

//#pragma pack(pop)
