#pragma once

#include "MFileRecord.h"

class MFileRecordFileVer : public MFileRecord
{
public:
	MFileRecordFileVer();
	virtual ~MFileRecordFileVer();

public:
	virtual BOOL Read(MRelationalDatabase* pRDBMS);
	virtual BOOL Write(MRelationalDatabase* pRDBMS);

};

