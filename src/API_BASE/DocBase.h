#pragma once

#include "../API_LIB/IObserver.h"

class MRelationalDatabase;
class AFX_EXT_CLASS CDocBase : public CDocument, public IObserver
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
	virtual int Update(UINT uiMsg, WPARAM wParam, LPARAM lParam) override;

public:
	MRelationalDatabase* GetRDBMS();
	void SetRDBMS(MRelationalDatabase* pRDBMS);

protected:
	std::shared_ptr<MRelationalDatabase> m_pRDBMS;

};

