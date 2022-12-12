#pragma once

class MFileRecord;
class MFileRecordFactory
{
	struct tagRecord
	{
		UINT uiType;
		UINT uiVer;
		CRuntimeClass* pRuntimeClass;

		tagRecord(UINT _uiType, UINT _uiVer, CRuntimeClass* _pRuntimeClass)
			: uiType(_uiType), uiVer(_uiVer), pRuntimeClass(_pRuntimeClass)
		{}
	};

	using PTR_RECORD = std::shared_ptr<MFileRecord>;
	using VEC_RECORD = std::vector<tagRecord>;
	using MAP_RECORD = std::unordered_map<UINT, VEC_RECORD>;

public:
	static MFileRecordFactory& Instance();

public:
	MFileRecordFactory();
	~MFileRecordFactory();

public:
	PTR_RECORD Create(UINT uiType, UINT uiVer);

	BOOL Register(UINT uiType, UINT uiVer, CRuntimeClass* pRuntimeClass);
	BOOL Unregister(UINT uiType, UINT uiVer);

protected:
	MAP_RECORD m_mRecord;

};

