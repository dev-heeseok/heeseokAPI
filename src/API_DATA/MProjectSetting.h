#pragma once

#include "../API_CORE/MBlock.h"

class AFX_EXT_CLASS MProjectSetting : public MBlock
{
public:
	MKEY key = 0; // KEY 는 가장 먼저 정의해야 한다.
	MString strName;

	DECLARE_PRIMARY_KEY(MProjectSetting, key)

public:
	MProjectSetting();
	virtual ~MProjectSetting();

public:
	virtual BOOL ChmodFile(MTableSpace* pTableSpace) override;
	virtual BOOL ChmodMomory(MTableSpace* pTableSpace) override;

public:
	void Initialize();

};

