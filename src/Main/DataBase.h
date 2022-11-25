#pragma once

#include "../API_CORE/MTableSpace.h"

class CDataBase : public MTableSpace
{
public:
	CDataBase();
	virtual ~CDataBase();

protected:
	virtual void ComposeList() override;

};

