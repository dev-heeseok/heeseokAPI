#include "pch.h"
#include "MSegmentBase.h"

MSegmentBase::MSegmentBase(MTableSpace* pTableSpace, int nType)
	: m_pTableSpace(pTableSpace)
	, m_nDataType(nType)
	, m_nFlag(0)
{
}

MSegmentBase::~MSegmentBase()
{
}
