#pragma once

#include "MSegmentBase.h"

class MTableSpace;

template <typename T>
class MSegment : public MSegmentBase
{
public:
	MSegment(MTableSpace* pTableSpace, int nDataType, int nHashSize)
		: MSegmentBase(pTableSpace, nDataType) 
	{}
	virtual ~MSegment()
	{}

public:


};