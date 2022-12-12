#pragma once

class MFileRecord;

class CDocBase;
class CDocStructure
{
public:
	static CDocStructure& Instance();

protected:
	CDocStructure();

public:
	~CDocStructure();

public:
	BOOL FileNew(CDocBase* pDoc);
	BOOL FileOpen(CDocBase* pDoc, CString strPathName);
	BOOL FileSave(CDocBase* pDoc, CString strPathName);
	BOOL FileClose(CDocBase* pDoc);

protected:
	BOOL Read(CDocBase* pDoc, CString strPathName);
	BOOL Write(CDocBase* pDoc, CString strPathName);


};

