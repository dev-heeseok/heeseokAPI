#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

class MSegmentBase;
class AFX_EXT_CLASS MTableSpace
{
	using SEGMENT_PTR = std::shared_ptr<MSegmentBase>;
	using SEGMENT_LIST = std::vector<SEGMENT_PTR>;
	using SEQUENCE_MAP = std::unordered_map<int, size_t>; // TODO. type to index

public:
	MTableSpace();
	virtual ~MTableSpace();

public:
	virtual void SetSegment(int nType, MSegmentBase* pSegment);
	virtual void Build();

protected:
	virtual void ComposeList() {}
	virtual void PreComposeList() {}
	virtual void LazyComposeList() {}

public:
	int GetCount();
	MSegmentBase* GetSegment(int nType);
	MSegmentBase* GetSegmentByIndex(int nIndex);

protected:
	SEGMENT_LIST m_segment;
	SEQUENCE_MAP m_sequence;

};