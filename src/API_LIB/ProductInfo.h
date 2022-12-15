#pragma once

class AFX_EXT_CLASS IProductInfo
{
	static IProductInfo* g_pInstance;

public:
	static IProductInfo& Instance();

protected:
	IProductInfo();

public:
	virtual ~IProductInfo();

public:
	virtual CString ProductName() = 0;
	virtual CString ProductDesc() = 0;
	virtual CString ProductVersion() = 0;
	virtual CString ProductExtension() = 0;
	virtual CString ProductFilter() = 0;

	virtual UINT ProductCode() = 0;
	virtual UINT ProductFullVer() = 0;
	virtual UINT ProductMajor() = 0;
	virtual UINT ProductMinor() = 0;
	virtual UINT ProductPatch() = 0;
	virtual UINT ProductBuild() = 0;


};

