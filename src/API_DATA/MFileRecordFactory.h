#pragma once

#include "MFileRecordDefine.h"

class MFileRecord;
class AFX_EXT_CLASS MFileRecordFactory final
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

#define DECLARE_RECORD(_class_name)\
DECLARE_DYNCREATE(_class_name)\
public:\
virtual UINT GetType() override;\

#define IMPLEMENT_RECORD(_class_name, _type, _ver)\
IMPLEMENT_DYNCREATE(_class_name, MFileRecord)\
UINT _class_name::GetType() { return static_cast<UINT>(_type); }\
BOOL b##_class_name = MFileRecordFactory::Instance().Register(static_cast<UINT>(_type), static_cast<UINT>(_ver), RUNTIME_CLASS(_class_name));