#pragma once

#include "../API_BASE/ProductInfo.h"

class CProductInfoImpl : public IProductInfo
{
public:
	CProductInfoImpl();
	virtual ~CProductInfoImpl();

public:
	virtual CString ProductName() override;
	virtual CString ProductDesc() override;
	virtual CString ProductVersion() override;
	virtual CString ProductExtension() override;
	virtual CString ProductFilter() override;

	virtual UINT ProductCode() override;
	virtual UINT ProductFullVer() override;
	virtual UINT ProductMajor() override;
	virtual UINT ProductMinor() override;
	virtual UINT ProductPatch() override;
	virtual UINT ProductBuild() override;

};

