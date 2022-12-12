#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Main.h"
#endif

#include "MainDoc.h"
#include "DocStructure.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMainDoc, CDocBase)

CMainDoc::CMainDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CMainDoc::~CMainDoc()
{
}

BEGIN_MESSAGE_MAP(CMainDoc, CDocBase)
	ON_COMMAND_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_BTN, ID_MAIN_RBMENU_DEV_EXAMPLE_BTN, OnRibbonCategory)
	ON_COMMAND_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_CHK, ID_MAIN_RBMENU_DEV_EXAMPLE_CHK, OnRibbonCategory)
	ON_COMMAND_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_CMB, ID_MAIN_RBMENU_DEV_EXAMPLE_CMB, OnRibbonCategory)
	ON_COMMAND_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_EDIT_CMB, ID_MAIN_RBMENU_DEV_EXAMPLE_EDIT_CMB, OnRibbonCategory)
	ON_COMMAND_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_MENU, ID_MAIN_RBMENU_DEV_EXAMPLE_MENU, OnRibbonCategory)
	ON_COMMAND_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM1, ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM1, OnRibbonCategory)
	ON_COMMAND_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM2, ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM2, OnRibbonCategory)
	ON_COMMAND_RANGE(ID_MAIN_RBMENU_DEV_UNIT_TEST_BTN, ID_MAIN_RBMENU_DEV_UNIT_TEST_BTN, OnRibbonCategory)

	ON_UPDATE_COMMAND_UI_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_BTN, ID_MAIN_RBMENU_DEV_EXAMPLE_BTN, OnRibbonCategoryUI)
	ON_UPDATE_COMMAND_UI_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_CHK, ID_MAIN_RBMENU_DEV_EXAMPLE_CHK, OnRibbonCategoryUI)
	ON_UPDATE_COMMAND_UI_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_CMB, ID_MAIN_RBMENU_DEV_EXAMPLE_CMB, OnRibbonCategoryUI)
	ON_UPDATE_COMMAND_UI_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_EDIT_CMB, ID_MAIN_RBMENU_DEV_EXAMPLE_EDIT_CMB, OnRibbonCategoryUI)
	ON_UPDATE_COMMAND_UI_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_MENU, ID_MAIN_RBMENU_DEV_EXAMPLE_MENU, OnRibbonCategoryUI)
	ON_UPDATE_COMMAND_UI_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM1, ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM1, OnRibbonCategoryUI)
	ON_UPDATE_COMMAND_UI_RANGE(ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM2, ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM2, OnRibbonCategoryUI)
	ON_UPDATE_COMMAND_UI_RANGE(ID_MAIN_RBMENU_DEV_UNIT_TEST_BTN, ID_MAIN_RBMENU_DEV_UNIT_TEST_BTN, OnRibbonCategoryUI)
END_MESSAGE_MAP()

BOOL CMainDoc::OnNewDocument()
{
	if (!CDocBase::OnNewDocument())
		return FALSE;

	return CDocStructure::Instance().FileNew(this);
}

BOOL CMainDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if(!CDocBase::OnOpenDocument(lpszPathName))
		return FALSE;

	return CDocStructure::Instance().FileOpen(this, lpszPathName);
}

BOOL CMainDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	if (!CDocStructure::Instance().FileSave(this, lpszPathName))
		return FALSE;

	return CDocBase::OnSaveDocument(lpszPathName);
}

void CMainDoc::OnCloseDocument()
{
	if (!CDocStructure::Instance().FileClose(this))
		return;

	CDocBase::OnCloseDocument();
}

void CMainDoc::Serialize(CArchive& ar)
{
	CDocBase::Serialize(ar);
}

int CMainDoc::Update(UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
	return CDocBase::Update(uiMsg, wParam, lParam);
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CMainDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CMainDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMainDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl* pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

#ifdef _DEBUG
void CMainDoc::AssertValid() const
{
	CDocBase::AssertValid();
}

void CMainDoc::Dump(CDumpContext& dc) const
{
	CDocBase::Dump(dc);
}
#endif //_DEBUG

void CMainDoc::OnRibbonCategory(UINT uiResID)
{
	switch (uiResID)
	{
	case ID_MAIN_RBMENU_DEV_EXAMPLE_BTN:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_CHK:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_CMB:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_EDIT_CMB:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_MENU:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM1:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM2:
	case ID_MAIN_RBMENU_DEV_UNIT_TEST_BTN:
	{

	}
	break;
	default:
		break;
	}
}

void CMainDoc::OnRibbonCategoryUI(CCmdUI* pCmdUI)
{
	switch (pCmdUI->m_nID)
	{

	case ID_MAIN_RBMENU_DEV_EXAMPLE_BTN:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_CHK:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_CMB:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_EDIT_CMB:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_MENU:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM1:
	case ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM2:
	case ID_MAIN_RBMENU_DEV_UNIT_TEST_BTN:
	{
		pCmdUI->Enable(TRUE);
	}
	break;
	default:
		break;
	}
}
