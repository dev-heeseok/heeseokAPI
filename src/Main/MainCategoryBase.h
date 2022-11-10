#pragma once

class CMainCategoryBase
{
public:
	CMainCategoryBase();
	virtual ~CMainCategoryBase();

public:
	virtual void SetMenu(CMFCRibbonBar* /*pRibbonBar*/) { ASSERT(0); }

protected:
	CMFCToolBarImages m_tbImages;

};

