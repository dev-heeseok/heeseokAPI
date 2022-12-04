#pragma once

#include "MProjectSetting.h"

#include "../API_CORE/MSchemaBase.hpp"

class AFX_EXT_CLASS MProjectSettingSchema : public MSchemaBase<MProjectSetting>
{
	constexpr static int SZ_HASH_PROJECT_SETTING = 100;

public:
	MProjectSettingSchema(MTableSpace* pTableSpace, UINT uiType);
	virtual ~MProjectSettingSchema();

public:
	virtual BOOL ProcessRelation() override;
	virtual void LazyDelete() override;



};

