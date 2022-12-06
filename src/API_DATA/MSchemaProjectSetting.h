#pragma once

#include "MProjectSetting.h"
#include "../API_CORE/MSchemaBase.hpp"

class AFX_EXT_CLASS MSchemaProjectSetting : public MSchemaBase<MProjectSetting>
{
	constexpr static int SZ_HASH_PROJECT_SETTING = 10;

public:
	MSchemaProjectSetting(MTableSpace* pTableSpace, UINT uiType);
	virtual ~MSchemaProjectSetting();

public:
	virtual BOOL ProcessRelation() override;


};
