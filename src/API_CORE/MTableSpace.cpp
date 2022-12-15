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
	for (auto pSchema : m_aSchema)
	{
		SAFE_DELETE(pSchema);
	}

	m_aSchema.clear();
	m_mSchema.clear();

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
	size_t nIndex = m_aSchema.size();

	auto itr = m_mSchema.find(uiType);
	if (itr != m_mSchema.end())
	{
		ASSERT(FALSE);

		size_t idxDel = itr->second;
		MSchema* pDelSchema = m_aSchema[idxDel];

		SAFE_DELETE(pDelSchema);

		auto itrDel = m_aSchema.begin() + idxDel;
		m_aSchema.erase(itrDel);
		m_mSchema.erase(itr);
	}

	m_aSchema.push_back(pSchema);
	m_mSchema.insert({ uiType, nIndex });
}

int MTableSpace::GetSchemaCount()
{
	return static_cast<int>(m_aSchema.size());
}

MSchema* MTableSpace::GetSchemaByType(UINT uiType)
{
	auto itr = m_mSchema.find(uiType);
	return itr != m_mSchema.end() ? m_aSchema[itr->second] : nullptr;
}

MSchema* MTableSpace::GetSchemaByIndx(int nIndex)
{
	int nCount = GetSchemaCount();
	return nIndex < nCount ? m_aSchema[nIndex] : nullptr;
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
