#include "pch.h"
#include "ProductInfo.h"

IProductInfo* IProductInfo::g_pInstance = nullptr;

IProductInfo& IProductInfo::Instance()
{
	return *g_pInstance;
}

IProductInfo::IProductInfo()
{
	ASSERT(g_pInstance == nullptr);
	g_pInstance = this;
}

IProductInfo::~IProductInfo()
{
}
