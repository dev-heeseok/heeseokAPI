#include "pch.h"
#include "MSchema.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MSchema::MSchema(MTableSpace* pTableSpace, UINT uiType)
	: m_pTableSpace(pTableSpace), m_uiType(uiType), m_uiFlag(0)
{
}

MSchema::~MSchema()
{
}
