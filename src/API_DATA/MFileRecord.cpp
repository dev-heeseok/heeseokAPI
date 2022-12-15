#include "pch.h"
#include "MFileRecord.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MFileRecord::MFileRecord()
{
}

MFileRecord::~MFileRecord()
{
}

BOOL MFileRecord::BuildBulkBundle(const tagBulkIO* pBulkIO, tagBulkBundle* pBulkBundle)
{
    return 0;
}
