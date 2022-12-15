#pragma once

#include "MFileRecord.h"
#include "MFileRecordFactory.h"

class MFileRecordFileVer : public MFileRecord
{
	DECLARE_RECORD(MFileRecordFileVer)

public:
	MFileRecordFileVer();
	virtual ~MFileRecordFileVer();

public:
	virtual BOOL Read(MRelationalDatabase* pRDBMS, MFileBulk* pFileBulk) override;
	virtual BOOL Write(MRelationalDatabase* pRDBMS, MFileBulk* pFileBulk) override;

};

