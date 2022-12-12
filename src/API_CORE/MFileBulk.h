#pragma once

class AFX_EXT_CLASS MFileBulk
{
public:
	MFileBulk();
	virtual ~MFileBulk();

public:
	BOOL Open(CString strFilePath, CString strMode);
	void Close();

public:

protected:
	FILE* m_pFile;

};

