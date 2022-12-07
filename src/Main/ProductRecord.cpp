#include "pch.h"
#include "ProductRecord.h"

#include "../API_DATA/MRelationalDatabase.h"
#include "../API_BASE/DocBase.h"

#include <filesystem>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace fs = std::filesystem;

CProductRecord& CProductRecord::Instance()
{
	static CProductRecord _instance;
	return _instance;
}

CProductRecord::CProductRecord()
{
}

CProductRecord::~CProductRecord()
{
}

BOOL CProductRecord::FileNew(CDocBase* pDoc)
{
	MRelationalDatabase* pRDBMS = new MRelationalDatabase();
	if (pRDBMS == nullptr)
	{
		TRACE(_T("[CProductRecord::FileNew] DB 생성 실패"));
		return FALSE;
	}

	pRDBMS->Attach(pDoc);

	pDoc->SetRDBMS(pRDBMS);

	return TRUE;
}

BOOL CProductRecord::FileOpen(CDocBase* pDoc, CString strPathName)
{
	fs::path fp(strPathName.GetBuffer());
	if (!fs::exists(fp))
	{
		TRACE(_T("[CProductRecord::FileOpen] Not exist file"));
		return FALSE;
	}

	CString strName = fp.stem().c_str();
	CString strExt = fp.extension().c_str();

	MRelationalDatabase* pRDBMS = new MRelationalDatabase();
	if (pRDBMS == nullptr)
	{
		TRACE(_T("[CProductRecord::FileOpen] DB 생성 실패"));
		return FALSE;
	}

	pRDBMS->Attach(pDoc);
	pRDBMS->BindingSchema();

	pDoc->SetRDBMS(pRDBMS);
	pDoc->SetTitle(strName);

	////////////////////////////////////////////////////

	return TRUE;
}

BOOL CProductRecord::FileSave(CDocBase* /*pDoc*/, CString /*strPartName*/)
{
	return TRUE;
}

BOOL CProductRecord::FileClose(CDocBase* pDoc)
{
	MRelationalDatabase* pRDBMS = pDoc->GetRDBMS();
	if (pRDBMS == nullptr)
	{
		TRACE(_T("[CProductRecord::FileClose] DB 소멸 실패"));
		return FALSE;
	}

	pRDBMS->Detach(pDoc);

	pDoc->SetRDBMS(nullptr);

	return TRUE;
}
