#include "pch.h"
#include "MTableSpace.h"
#include "MSchema.h"

#include "../API_LIB/StandardFuncLibrary.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace util;

MTableSpace::MTableSpace()
	: m_bTR(FALSE)
{
}

MTableSpace::~MTableSpace()
{
}

void MTableSpace::PushNotify(const tagNotification& data)
{
	m_aNotify.push_back(data);
}

void MTableSpace::BindingSchema()
{
	PrebuildSchema();

	BuildSchema();

	PostbuildSchema();
}

void MTableSpace::AppendSchema(MSchema* pSchema)
{
	if (pSchema == nullptr)
		return;

	UINT uiType = pSchema->GetType();
	int nIndex = static_cast<int>(m_aSchema.size());

	m_mSchema.insert({ uiType, nIndex });
	m_aSchema.push_back(PTR_SCHEMA(pSchema));
}

int MTableSpace::GetSchemaCount()
{
	return static_cast<int>(m_aSchema.size());
}

MSchema* MTableSpace::GetSchemaByType(UINT uiType)
{
	auto itr = m_mSchema.find(uiType);
	return itr != m_mSchema.end() ? m_aSchema[itr->second].get() : nullptr;
}

MSchema* MTableSpace::GetSchemaByIndx(int nIndex)
{
	int nCount = GetSchemaCount();
	return nIndex < nCount ? m_aSchema[nIndex].get() : nullptr;
}

BOOL MTableSpace::BeginTR(CString strName)
{
	for (auto pSchema : m_aSchema)
		pSchema->SetFlag(0);

	m_aNotify.clear();
	m_bTR = TRUE;

	return TRUE;
}

BOOL MTableSpace::CommitTR()
{
	for (auto pSchema : m_aSchema)
		pSchema->ProcessRelation();

	m_aNotify;
	Notify(EnumIndex(NMessage::kUpdateDB), 0, 0);

	for (auto pSchema : m_aSchema)
		pSchema->LazyDelete();

	m_aNotify.clear();
	m_bTR = FALSE;

	return TRUE;
}

BOOL MTableSpace::RollbackTR()
{
	m_aNotify.clear();
	m_bTR = FALSE;

	return FALSE;
}
