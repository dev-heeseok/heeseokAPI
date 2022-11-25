#pragma once

#include "../API_LIB/NotifyObserver.h"

class AFX_EXT_CLASS CDocBase : public CDocument, CNotifyObserver
{
public:
	CDocBase();
	virtual ~CDocBase();

public:
	virtual BOOL OnNewDocument() override;
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName) override;
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName) override;
	virtual void OnCloseDocument() override;

protected:
	virtual int Notify(UINT uiMsg, WPARAM wParam, LPARAM lParam) override;

};

