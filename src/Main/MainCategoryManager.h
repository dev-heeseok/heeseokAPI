#pragma once

class CMainCategoryBase;
class CMainCategoryManager
{
public:
	CMainCategoryManager();
	virtual ~CMainCategoryManager();

public:
	void SetMenu(CMFCRibbonBar* pRibbonBar);

private:
	using CATEGORY_PTR = std::shared_ptr<CMainCategoryBase>;
	std::vector<CATEGORY_PTR> m_aCategory;

};

