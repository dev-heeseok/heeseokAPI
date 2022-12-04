#include "pch.h"
#include "MProjectSetting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MProjectSetting::MProjectSetting()
{
}

MProjectSetting::~MProjectSetting()
{
}

BOOL MProjectSetting::ChmodFile(MTableSpace* /*pTableSpace*/)
{
	return TRUE;
}

BOOL MProjectSetting::ChmodMomory(MTableSpace* /*pTableSpace*/)
{
	return TRUE;
}

void MProjectSetting::Initialize()
{
	key = 0;
	strName = _T("default");
}
