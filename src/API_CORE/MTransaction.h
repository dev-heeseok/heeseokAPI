#pragma once

class MTableSpace;
class AFX_EXT_CLASS MTransaction final
{
public:
	MTransaction(MTableSpace* pTableSpace);
	~MTransaction();

public:
	BOOL Begin(CString strName);
	BOOL Commit();
	BOOL Rollback();

protected:
	MTableSpace* m_pTableSpace;

};

