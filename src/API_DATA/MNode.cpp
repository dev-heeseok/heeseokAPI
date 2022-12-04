#include "pch.h"
#include "MNode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MNode::MNode()
{
	Initialize();
}

MNode::~MNode()
{
}

BOOL MNode::ChmodFile(MTableSpace* /*pTableSpace*/)
{
	return TRUE;
}

BOOL MNode::ChmodMomory(MTableSpace* /*pTableSpace*/)
{
	return TRUE;
}

void MNode::Initialize()
{
	key = 0;
	vPos3d.Set(0);
}