#include "pch.h"
#include "DocBase.h"
#include "MRelationalDatabase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDocBase::CDocBase()
{
	m_pRDBMS = std::make_shared<MRelationalDatabase>();
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