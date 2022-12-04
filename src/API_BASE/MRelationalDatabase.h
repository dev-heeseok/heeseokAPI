#pragma once

#include "../API_CORE/MTableSpace.h"

class AFX_EXT_CLASS MRelationalDatabase : public MTableSpace
{
public:
	MRelationalDatabase();
	virtual ~MRelationalDatabase();

protected:
	virtual void PrebuildSchema() override;
	virtual void PostbuildSchema() override;
	virtual void BuildSchema() override;

};

