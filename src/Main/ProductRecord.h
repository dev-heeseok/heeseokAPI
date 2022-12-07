#pragma once

class CDocBase;
class CProductRecord
{
public:
	static CProductRecord& Instance();

protected:
	CProductRecord();

public:
	~CProductRecord();

public:
	BOOL FileNew(CDocBase* pDoc);
	BOOL FileOpen(CDocBase* pDoc, CString strPathName);
	BOOL FileSave(CDocBase* pDoc, CString strPathName);
	BOOL FileClose(CDocBase* pDoc);

};

