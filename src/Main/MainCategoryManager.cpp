#include "pch.h"
#include "MainCategoryManager.h"
#include "MainCategoryDevelop.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMainCategoryManager::CMainCategoryManager()
{
	if (auto pCategory = std::make_shared<CMainCategoryDevelop>())
		m_aCategory.push_back(pCategory);
}

CMainCategoryManager::~CMainCategoryManager()
{
}

void CMainCategoryManager::SetMenu(CMFCRibbonBar* pRibbonBar)
{
	for (auto pCategory : m_aCategory)
	{
		if (pCategory)
			pCategory->SetMenu(pRibbonBar);
	}
}
