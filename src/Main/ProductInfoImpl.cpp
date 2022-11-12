#include "pch.h"
#include "ProductInfoImpl.h"
#include "Version.h"

CProductInfoImpl _instance;

CProductInfoImpl::CProductInfoImpl()
{
}

CProductInfoImpl::~CProductInfoImpl()
{
}

CString CProductInfoImpl::ProductName()
{
	return CString(PRODUCT_NAME);
}

CString CProductInfoImpl::ProductDesc()
{
	return CString(PRODUCT_DESC);
}

CString CProductInfoImpl::ProductVersion()
{
	return CString(PRODUCT_VER);
}

CString CProductInfoImpl::ProductExtension()
{
	return CString(FILE_EXT);
}

CString CProductInfoImpl::ProductFilter()
{
	return CString(FILE_FILTER);
}

UINT CProductInfoImpl::ProductCode()
{
	return PRODUCT_CODE;
}

UINT CProductInfoImpl::ProductFullVer()
{
	return PRODUCT_FULL_VER;
}

UINT CProductInfoImpl::ProductMajor()
{
	return PRODUCT_VER_MAJOR;
}

UINT CProductInfoImpl::ProductMinor()
{
	return PRODUCT_VER_MINOR;
}

UINT CProductInfoImpl::ProductPatch()
{
	return PRODUCT_VER_PATCH;
}

UINT CProductInfoImpl::ProductBuild()
{
	return PRODUCT_VER_BUILD;
}
