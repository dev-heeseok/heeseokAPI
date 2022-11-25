#pragma once

#include "../API_BASE/DocBase.h"

class CMainDoc : public CDocBase
{
	DECLARE_DYNCREATE(CMainDoc)

protected:
	CMainDoc() noexcept;

public:
	virtual ~CMainDoc();

public:
	virtual BOOL OnNewDocument() override;
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName) override;
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName) override;
	virtual void OnCloseDocument() override;

	[[deprecated]]
	virtual void Serialize(CArchive& ar) override;

	virtual int Notify(UINT uiMsg, WPARAM wParam, LPARAM lParam) override;

#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

protected:
	afx_msg void OnRibbonCategory(UINT uiResID);
	afx_msg void OnRibbonCategoryUI(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()

};
