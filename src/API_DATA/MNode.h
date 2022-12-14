#pragma once

#include "../API_CORE/MBlock.h"

#pragma pack(push, 4)

class AFX_EXT_CLASS MNode : public MBlock
{
public:
	MKEY key = 0; // TODO. MKEY 는 반드시 첫번째 인자여야 한다.
	MVector3d vPos3d;

	DECLARE_PRIMARY_KEY(MNode, key)

public:
	MNode();
	virtual ~MNode();

public:
	virtual BOOL ChmodFile(MTableSpace* pTableSpace) override;
	virtual BOOL ChmodMomory(MTableSpace* pTableSpace) override;

public:
	void Initialize();

};

#pragma pack(pop)