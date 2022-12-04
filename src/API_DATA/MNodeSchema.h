#pragma once

#include "../API_CORE/MTableSpace.h"
#include "../API_CORE/MSchemaBase.hpp"

#include "MNode.h"

class AFX_EXT_CLASS MNodeSchema : public MSchemaBase<MNode>
{
	constexpr static int SZ_HASH_NODE = 1000;

public:
	MNodeSchema(MTableSpace* pTableSpace, int nDataType);
	virtual ~MNodeSchema();

public:
	virtual BOOL ProcessRelation() override;
	virtual void LazyDelete() override;

};

