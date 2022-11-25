#include "pch.h"
#include "DataBase.h"

#include "../API_CORE/MSegmentBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDataBase::CDataBase()
{
}

CDataBase::~CDataBase()
{
}

void ComposeItem(CDataBase* pDataBase, MSegmentBase* pSegment)
{
	pDataBase->SetSegment(pSegment->GetDataType(), pSegment);
}

void CDataBase::ComposeList()
{
}
