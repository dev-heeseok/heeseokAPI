#include "pch.h"
#include "MFileRecordFileVer.h"

#include "../API_LIB/StandardFuncLibrary.h"
#include "../API_LIB/ProductInfo.h"
#include "../API_CORE/MFileBulkDefine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace util;

struct tagFileVer
{
	UINT uiFileVer;
	UINT uiFullVer;

	BEGIN_BULK_IO(tagFileVer)
		BULK_IO_DEF_FIXED(_T("FILE_VER"), tagFileVer, UINT, uiFileVer)
		BULK_IO_DEF_FIXED(_T("FULL_VER"), tagFileVer, UINT, uiFullVer)
	END_BULK_IO()
};


IMPLEMENT_RECORD(MFileRecordFileVer, RecordType::kFileVer, RecordVer::k100)

MFileRecordFileVer::MFileRecordFileVer()
{
}

MFileRecordFileVer::~MFileRecordFileVer()
{
}

BOOL MFileRecordFileVer::Read(MRelationalDatabase* pRDBMS, MFileBulk* pFileBulk)
{
	return TRUE;
}

BOOL MFileRecordFileVer::Write(MRelationalDatabase* pRDBMS, MFileBulk* pFileBulk)
{
	const tagBulkIO* pBulkIO = tagFileVer::GetBulkIO();
	tagBulkBundle tBulkBundle;
	
	if (!BuildBulkBundle(pBulkIO, &tBulkBundle))
		return FALSE;


	tagBulkHead tHead;
	tHead.nID = GetType();
	tHead.nValue = 0; // bulk size

	tagFileVer tFileVer;
	tFileVer.uiFileVer = EnumIndex(RecordVer::k100);
	tFileVer.uiFullVer = IProductInfo::Instance().ProductFullVer();







	return TRUE;
}
