#pragma once

class AFX_EXT_CLASS CDocBase : public CDocument
{
public:
	CDocBase();
	virtual ~CDocBase();

public:
	virtual BOOL OnNewDocument() override;
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName) override;
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName) override;
	virtual void OnCloseDocument() override;

};

