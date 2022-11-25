#include "pch.h"
#include "ProductSerialize.h"

CProductSerialize& CProductSerialize::Instance()
{
	static CProductSerialize _instance;
	return _instance;
}

CProductSerialize::CProductSerialize()
{
}

CProductSerialize::~CProductSerialize()
{
}

BOOL CProductSerialize::OnProductNew(CDocBase* /*pDoc*/)
{
	return TRUE;
}

BOOL CProductSerialize::OnProductOpen(CDocBase* /*pDoc*/, CString /*strPartName*/)
{
	return TRUE;
}

BOOL CProductSerialize::OnProductSave(CDocBase* /*pDoc*/, CString /*strPartName*/)
{
	return TRUE;
}

BOOL CProductSerialize::OnProductClose(CDocBase* /*pDoc*/)
{
	return TRUE;
}
