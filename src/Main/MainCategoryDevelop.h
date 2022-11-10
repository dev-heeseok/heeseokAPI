#pragma once

#include "MainCategoryBase.h"

class CMainCategoryDevelop : public CMainCategoryBase
{
public:
	CMainCategoryDevelop();
	virtual ~CMainCategoryDevelop();

public:
	virtual void SetMenu(CMFCRibbonBar* pRibbonBar) override;

private:
	void BuildCategory();
	void BuildExamplePanel(CMFCRibbonPanel* pPanel);
	void BuildUnitTestPanel(CMFCRibbonPanel* pPanel);

	void RebuildMenu(CMFCRibbonButton* pRibbonButton);

private:
	CMFCRibbonBar* m_pRibbonBar = nullptr;
	CMFCRibbonCategory* m_pCategory = nullptr;

	CMenu m_Menu;
};