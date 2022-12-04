#include "pch.h"
#include "MProjectSettingSchema.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MProjectSettingSchema::MProjectSettingSchema(MTableSpace* pTableSpace, UINT uiType)
	: MSchemaBase<MProjectSetting>(pTableSpace, uiType, SZ_HASH_PROJECT_SETTING)
{
}

MProjectSettingSchema::~MProjectSettingSchema()
{
}

BOOL MProjectSettingSchema::ProcessRelation()
{
	return 0;
}

void MProjectSettingSchema::LazyDelete()
{
}