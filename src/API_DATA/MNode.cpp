#include "pch.h"
#include "MNode.h"

MNode::MNode()
{
	Initialize();
}

MNode::~MNode()
{
}

void MNode::Initialize()
{
	Key = 0;
	vPos3d.Set(0);
}

BOOL MNode::ChmodRead(MSegment* /*pSegment*/)
{
	return TRUE;
}

BOOL MNode::ChmodWrite(MSegment* /*pSegment*/)
{
	return TRUE;
}
