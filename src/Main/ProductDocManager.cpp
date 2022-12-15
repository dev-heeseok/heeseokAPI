#include "pch.h"
#include "ProductDocManager.h"

#include "../API_LIB/ProductInfo.h"

BOOL CProductDocManager::DoPromptFileName(CString& fileName, UINT nIDSTitle, DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate* /*pTemplate*/)
{
	CString title;
	VERIFY(title.LoadString(nIDSTitle));

	CString ext = IProductInfo::Instance().ProductExtension();
	CString filter = IProductInfo::Instance().ProductFilter();

	CFileDialog dlg(bOpenFileDialog, ext, fileName, lFlags, filter);
	if (dlg.DoModal() != IDOK)
		return FALSE;

	fileName = dlg.GetPathName();

	return TRUE;
}
