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

int CDocBase::Notify(UINT /*uiMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	return 0;
}