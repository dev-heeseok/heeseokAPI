#include "pch.h"
#include "resource.h"
#include "MainCategoryDevelop.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMainCategoryDevelop::CMainCategoryDevelop()
{
	m_Menu.CreateMenu();
}

CMainCategoryDevelop::~CMainCategoryDevelop()
{
	m_Menu.DestroyMenu();
}

void CMainCategoryDevelop::SetMenu(CMFCRibbonBar* pRibbonBar)
{
	m_pRibbonBar = pRibbonBar;

	BuildCategory();
}

void CMainCategoryDevelop::BuildCategory()
{
	m_pCategory = m_pRibbonBar->AddCategory(_T("Develop"), 0, 0);

	if (auto pPanel = m_pCategory->AddPanel(_T("Example")))
	{
		pPanel->SetCenterColumnVert(TRUE);

		BuildExamplePanel(pPanel);
	}

	if (auto pPanel = m_pCategory->AddPanel(_T("Unit Test")))
	{
		BuildUnitTestPanel(pPanel);
	}

}

void CMainCategoryDevelop::BuildExamplePanel(CMFCRibbonPanel* pPanel)
{
	if (auto pButton = new CMFCRibbonButton(ID_MAIN_RBMENU_DEV_EXAMPLE_BTN, _T("Button"), -1, -1))
	{
		pButton->SetToolTipText(_T("Button Tooltip"));
		pButton->SetDescription(_T("Button Description"));

		pPanel->Add(pButton);
	}

	if (auto pButtonMenu = new CMFCRibbonButton(ID_MAIN_RBMENU_DEV_EXAMPLE_MENU, _T("Menu Button"), -1, -1))
	{
		pButtonMenu->SetToolTipText(_T("Menu Button Tooltip"));
		pButtonMenu->SetDescription(_T("Menu Button Description"));

		RebuildMenu(pButtonMenu);

		pPanel->Add(pButtonMenu);
	}

	if (auto pCheckBox = new CMFCRibbonCheckBox(ID_MAIN_RBMENU_DEV_EXAMPLE_CHK, _T("CheckBox")))
	{
		pPanel->Add(pCheckBox);
	}

	if (auto pComboBox = new CMFCRibbonComboBox(ID_MAIN_RBMENU_DEV_EXAMPLE_EDIT_CMB, TRUE, 70, _T("EditBox"), -1))
	{
		pComboBox->SetToolTipText(_T("HasEdit ComboBox Tooltip"));
		pComboBox->SetDescription(_T("HasEdit ComboBox Description"));

		pComboBox->AddItem(_T("Item1"), 1);
		pComboBox->AddItem(_T("Item2"), 2);
		pComboBox->SelectItem(1);

		pPanel->Add(pComboBox);
	}

	if (auto pComboBox = new CMFCRibbonComboBox(ID_MAIN_RBMENU_DEV_EXAMPLE_CMB, FALSE, 70, _T("ComboBox"), -1))
	{
		pComboBox->SetToolTipText(_T("ComboBox Tooltip"));
		pComboBox->SetDescription(_T("ComboBox Description"));

		pComboBox->AddItem(_T("Item1"), 1);
		pComboBox->AddItem(_T("Item2"), 2);
		pComboBox->SelectItem(1);

		pPanel->Add(pComboBox);
	}
}

void CMainCategoryDevelop::BuildUnitTestPanel(CMFCRibbonPanel* pPanel)
{
	if (auto pButton = new CMFCRibbonButton(ID_MAIN_RBMENU_DEV_UNIT_TEST_BTN, _T("Button"), -1, -1))
	{
		pButton->SetToolTipText(_T("Button Tooltip"));
		pButton->SetDescription(_T("Button Description"));

		pPanel->Add(pButton);
	}

}

void CMainCategoryDevelop::RebuildMenu(CMFCRibbonButton* pRibbonButton)
{
	if (m_Menu.GetMenuItemCount() > 0)
	{
		pRibbonButton->RemoveAllSubItems();
		m_Menu.ModifyMenu(0, MF_BYPOSITION | MF_BYCOMMAND, ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM1, (wchar_t*)(LPCTSTR)(_T("Menu1")));
		m_Menu.ModifyMenu(1, MF_BYPOSITION | MF_BYCOMMAND, ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM2, (wchar_t*)(LPCTSTR)(_T("Menu2")));
		pRibbonButton->SetMenu(m_Menu.GetSafeHmenu());
	}
	else
	{
		pRibbonButton->RemoveAllSubItems();
		m_Menu.AppendMenu(MF_STRING | MF_BYCOMMAND, ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM1, (wchar_t*)(LPCTSTR)(_T("Menu1")));
		m_Menu.AppendMenu(MF_STRING | MF_BYCOMMAND, ID_MAIN_RBMENU_DEV_EXAMPLE_MENU_ITEM2, (wchar_t*)(LPCTSTR)(_T("Menu2")));
		pRibbonButton->SetMenu(m_Menu.GetSafeHmenu());
	}
}
