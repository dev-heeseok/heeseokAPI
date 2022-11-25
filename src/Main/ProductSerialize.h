#pragma once

class CDocBase;
class CProductSerialize
{
public:
	static CProductSerialize& Instance();

protected:
	CProductSerialize();

public:
	~CProductSerialize();

public:
	BOOL OnProductNew(CDocBase* pDoc);
	BOOL OnProductOpen(CDocBase* pDoc, CString strPartName);
	BOOL OnProductSave(CDocBase* pDoc, CString strPartName);
	BOOL OnProductClose(CDocBase* pDoc);

};

