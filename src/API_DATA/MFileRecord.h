#pragma once

struct tagBulkIO;
struct tagBulkBundle;

class MFileBulk;
class MRelationalDatabase;
class AFX_EXT_CLASS MFileRecord : public CObject
{
public:
	MFileRecord();
	virtual ~MFileRecord();

public:
	virtual UINT GetType() = 0; // macro define

	virtual BOOL Read(MRelationalDatabase* pRDBMS, MFileBulk* pFileBulk) = 0;
	virtual BOOL Write(MRelationalDatabase* pRDBMS, MFileBulk* pFileBulk) = 0;

protected:
	BOOL BuildBulkBundle(const tagBulkIO* pBulkIO, tagBulkBundle* pBulkBundle);

};

