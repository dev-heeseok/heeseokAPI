#include "pch.h"
#include "MNodeSchema.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MNodeSchema::MNodeSchema(MTableSpace* pTableSpace, int nDataType)
	: MSchemaBase<MNode>(pTableSpace, nDataType, SZ_HASH_NODE)
{
}

MNodeSchema::~MNodeSchema()
{
}

BOOL MNodeSchema::ProcessRelation()
{
	return 0;
}

void MNodeSchema::LazyDelete()
{
}
