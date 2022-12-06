#include "pch.h"
#include "MSchemaProjectSetting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MSchemaProjectSetting::MSchemaProjectSetting(MTableSpace* pTableSpace, UINT uiType)
	: MSchemaBase<MProjectSetting>(pTableSpace, uiType, SZ_HASH_PROJECT_SETTING)
{
}

MSchemaProjectSetting::~MSchemaProjectSetting()
{
}

BOOL MSchemaProjectSetting::ProcessRelation()
{
	return 0;
}