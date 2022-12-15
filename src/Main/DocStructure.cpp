#include "pch.h"
#include "DocStructure.h"

#include "../API_CORE/MFileBulkDefine.h"
#include "../API_CORE/MFileBulk.h"
#include "../API_CORE/MSchema.h"
#include "../API_DATA/MRelationalDatabase.h"
#include "../API_DATA/MFileRecordDefine.h"
#include "../API_DATA/MFileRecord.h"
#include "../API_DATA/MFileRecordFactory.h"
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
	pRDBMS->BindingSchema();

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
	return TRUE;
}

BOOL CDocStructure::Write(CDocBase* pDoc, CString strPathName)
{
	MFileBulk fBulk;
	if (!fBulk.Open(strPathName, _T("wb")))
		return FALSE;

	try
	{
		MRelationalDatabase* pRDBMS = pDoc->GetRDBMS();

		int nRecordNum = static_cast<int>(RecordType::kNum);
		for (int i = 0; i < nRecordNum; ++i)
		{
			// TODO. profile record type
			RecordType kType = static_cast<RecordType>(i);

			UINT uiType = static_cast<UINT>(kType);
			UINT uiVer = static_cast<UINT>(RECORD_VERSION_LATEST);

			auto pFileRecord = MFileRecordFactory::Instance().Create(uiType, uiVer);
			if (pFileRecord && pFileRecord->Write(pRDBMS, &fBulk))
			{
				// Unknown
			}
		}
	}
	catch (...)
	{
		ASSERT(FALSE);
	}

	fBulk.Close();

	return TRUE;
}
