#include "pch.h"
#include "DocStructure.h"

#include "../API_DATA/MRelationalDatabase.h"
#include "../API_DATA/MFileRecord.h"
#include "../API_BASE/DocBase.h"

#include <filesystem>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace fs = std::filesystem;

CDocStructure& CDocStructure::Instance()
{
	static CDocStructure _instance;
	return _instance;
}

CDocStructure::CDocStructure()
{
}

CDocStructure::~CDocStructure()
{
}

BOOL CDocStructure::FileNew(CDocBase* pDoc)
{
	MRelationalDatabase* pRDBMS = new MRelationalDatabase();
	if (pRDBMS == nullptr)
	{
		TRACE(_T("[CDocStructure::FileNew] DB 생성 실패\n"));
		return FALSE;
	}

	pRDBMS->Attach(pDoc);

	pDoc->SetRDBMS(pRDBMS);

	return TRUE;
}

BOOL CDocStructure::FileOpen(CDocBase* pDoc, CString strPathName)
{
	fs::path fp(strPathName.GetBuffer());
	if (!fs::exists(fp))
	{
		TRACE(_T("[CDocStructure::FileOpen] Not exist file\n"));
		return FALSE;
	}

	CString strName = fp.stem().c_str();
	CString strExt = fp.extension().c_str();

	MRelationalDatabase* pRDBMS = new MRelationalDatabase();
	if (pRDBMS == nullptr)
	{
		TRACE(_T("[CDocStructure::FileOpen] DB 생성 실패\n"));
		return FALSE;
	}

	pRDBMS->Attach(pDoc);
	pRDBMS->BindingSchema();

	pDoc->SetRDBMS(pRDBMS);
	pDoc->SetTitle(strName);

	return Read(pDoc, strPathName);
}

BOOL CDocStructure::FileSave(CDocBase* pDoc, CString strPartName)
{
	return Write(pDoc, strPartName);
}

BOOL CDocStructure::FileClose(CDocBase* pDoc)
{
	MRelationalDatabase* pRDBMS = pDoc->GetRDBMS();
	if (pRDBMS == nullptr)
	{
		TRACE(_T("[CDocStructure::FileClose] DB 소멸 실패\n"));
		return FALSE;
	}

	pRDBMS->Detach(pDoc);

	pDoc->SetRDBMS(nullptr);

	return TRUE;
}

BOOL CDocStructure::Read(CDocBase* pDoc, CString strPathName)
{
	//MFileRecord record;

	//if (!Read(pDoc, strPathName))
	//{
	//	TRACE(_T("[CDocStructure::FileOpen] DB Open 실패\n"));
	//	return FALSE;
	//}

	return 0;
}

BOOL CDocStructure::Write(CDocBase* pDoc, CString strPathName)
{
	//MFileRecord record;
	//record.Write();

	return 0;
}
