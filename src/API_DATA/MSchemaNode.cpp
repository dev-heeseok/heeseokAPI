#include "pch.h"
#include "MSchemaNode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MSchemaNode::MSchemaNode(MTableSpace* pTableSpace, UINT uiType)
	: MSchemaBase<MNode>(pTableSpace, uiType, SZ_HASH_NODE)
{
}

MSchemaNode::~MSchemaNode()
{
}

BOOL MSchemaNode::ProcessRelation()
{
	return 0;
}