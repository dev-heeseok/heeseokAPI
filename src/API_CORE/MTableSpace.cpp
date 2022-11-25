#include "pch.h"
#include "MTableSpace.h"
#include "MSegmentBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MTableSpace::MTableSpace()
{
}

MTableSpace::~MTableSpace()
{
}

void MTableSpace::SetSegment(int nType, MSegmentBase* pSegment)
{
	auto itr = m_sequence.find(nType);
	if (itr != m_sequence.cend())
	{
		ASSERT(FALSE); // TODO. duplicated type
		m_segment.erase(m_segment.begin() + itr->second);
		m_sequence.erase(itr);
	}

	size_t index = m_segment.size();

	m_sequence.insert({ nType, index });
	m_segment.push_back(std::shared_ptr<MSegmentBase>(pSegment));
}

void MTableSpace::Build()
{
	PreComposeList();

	ComposeList();

	LazyComposeList();
}

int MTableSpace::GetCount()
{
	return static_cast<int>(m_segment.size());
}

MSegmentBase* MTableSpace::GetSegment(int nType)
{
	auto itr = m_sequence.find(nType);
	if (itr == m_sequence.cend())
	{
		ASSERT(FALSE);
		return nullptr;
	}

	size_t index = itr->second;

	return m_segment[index].get();
}

MSegmentBase* MTableSpace::GetSegmentByIndex(int nIndex)
{
	if (nIndex >= GetCount())
	{
		ASSERT(FALSE);
		return nullptr;
	}

	return m_segment[nIndex].get();
}
