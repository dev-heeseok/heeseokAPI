#pragma once

#include "../API_CORE/MTableSpace.h"
#include "../API_CORE/MSchemaBase.hpp"

#include "MNode.h"

class AFX_EXT_CLASS MSchemaNode : public MSchemaBase<MNode>
{
	constexpr static int SZ_HASH_NODE = 1000;

public:
	MSchemaNode(MTableSpace* pTableSpace, UINT uiType);
	virtual ~MSchemaNode();

public:
	virtual BOOL ProcessRelation() override;

};

