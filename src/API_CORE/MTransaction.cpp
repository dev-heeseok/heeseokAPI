#include "pch.h"
#include "MTransaction.h"
#include "MTableSpace.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MTransaction::MTransaction(MTableSpace* pTableSpace)
	: m_pTableSpace(pTableSpace)
{
}

MTransaction::~MTransaction()
{
	ASSERT(!m_pTableSpace->IsTR());
	
	if (m_pTableSpace->IsTR()) 
		Rollback();
}

BOOL MTransaction::Begin(CString strName)
{
	ASSERT(!m_pTableSpace->IsTR());
	return m_pTableSpace->BeginTR(strName);
}

BOOL MTransaction::Commit()
{
	ASSERT(m_pTableSpace->IsTR());
	return m_pTableSpace->CommitTR();
}

BOOL MTransaction::Rollback()
{
	ASSERT(m_pTableSpace->IsTR());
	return m_pTableSpace->RollbackTR();
}
