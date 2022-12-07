#include "pch.h"
#include "DocBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDocBase::CDocBase()
{
}

CDocBase::~CDocBase()
{
}

BOOL CDocBase::OnNewDocument()
{
	return CDocument::OnNewDocument();
}

BOOL CDocBase::OnOpenDocument(LPCTSTR lpszPathName)
{
	return CDocument::OnOpenDocument(lpszPathName);
}

BOOL CDocBase::OnSaveDocument(LPCTSTR lpszPathName)
{
	return CDocument::OnSaveDocument(lpszPathName);
}

void CDocBase::OnCloseDocument()
{
	CDocument::OnCloseDocument();

}

int CDocBase::Update(UINT /*uiMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	return 0;
}

MRelationalDatabase* CDocBase::GetRDBMS()
{
	return m_pRDBMS.get();
}

void CDocBase::SetRDBMS(MRelationalDatabase* pRDBMS)
{
	if (pRDBMS) m_pRDBMS = std::shared_ptr<MRelationalDatabase>(pRDBMS);
	else m_pRDBMS.reset();
}