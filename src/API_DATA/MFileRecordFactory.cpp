#include "pch.h"
#include "MFileRecordFactory.h"
#include "MFileRecord.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MFileRecordFactory& MFileRecordFactory::Instance()
{
	static MFileRecordFactory _instance;
	return _instance;
}

MFileRecordFactory::MFileRecordFactory()
{
}

MFileRecordFactory::~MFileRecordFactory()
{
}

MFileRecordFactory::PTR_RECORD MFileRecordFactory::Create(UINT uiType, UINT uiVer)
{
	auto itr = m_mRecord.find(uiType);
	if (itr == m_mRecord.end())
	{
		ASSERT(FALSE);
		return nullptr;
	}

	VEC_RECORD& aRecord = itr->second;

	auto itrFind = std::find_if(aRecord.begin(), aRecord.end(),
		[uiVer](const tagRecord& src) { return src.uiVer == uiVer; });

	auto pCreateObject = (*itrFind).pRuntimeClass->CreateObject();
	auto pFileRecord = static_cast<MFileRecord*>(pCreateObject);

	return PTR_RECORD(pFileRecord);
}

BOOL MFileRecordFactory::Register(UINT uiType, UINT uiVer, CRuntimeClass* pRuntimeClass)
{
	auto itr = m_mRecord.find(uiType);
	if (itr != m_mRecord.end())
	{
		VEC_RECORD& aRecord = itr->second;

		auto itrFind = std::find_if(aRecord.begin(), aRecord.end(),
			[uiVer](const tagRecord& src) { return src.uiVer == uiVer; });

		ASSERT(itrFind == aRecord.end());

		aRecord.push_back({ uiType, uiVer, pRuntimeClass });
	}
	else
	{
		VEC_RECORD aRecord;

		aRecord.push_back({ uiType, uiVer, pRuntimeClass });

		m_mRecord.insert({ uiType, aRecord });
	}

	return TRUE;
}

BOOL MFileRecordFactory::Unregister(UINT uiType, UINT uiVer)
{
	auto itr = m_mRecord.find(uiType);

	if (itr != m_mRecord.end())
	{
		VEC_RECORD& aRecord = itr->second;

		auto itrFind = std::find_if(aRecord.begin(), aRecord.end(),
			[uiVer](const tagRecord& src) { return src.uiVer == uiVer; });

		ASSERT(itrFind != aRecord.end());

		aRecord.erase(itrFind);
	}

	return TRUE;
}
