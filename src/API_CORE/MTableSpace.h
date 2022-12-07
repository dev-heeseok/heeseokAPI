#pragma once

#include "NotifySubject.h"

class MSchema;
class MTransaction;
class AFX_EXT_CLASS MTableSpace : public CNotifySubject
{
	friend MTransaction;

	using PTR_SCHEMA = std::shared_ptr<MSchema>;
	using VEC_SCHEMA = std::vector<PTR_SCHEMA>;
	using MAP_SCHEMA = std::unordered_map<UINT, int>; // type to schema index

public:
	MTableSpace();
	virtual ~MTableSpace();

protected:
	virtual void PrebuildSchema() = 0;
	virtual void PostbuildSchema() = 0;
	virtual void BuildSchema() = 0;

public:
	BOOL IsTR() { return m_bTR; }
	void PushNotify(const tagNotification& data);

	void BindingSchema();
	void AppendSchema(MSchema* pSchema);

	int GetSchemaCount();
	MSchema* GetSchemaByType(UINT uiType);
	MSchema* GetSchemaByIndx(int nIndex);
	
protected:
	BOOL BeginTR(CString strName);
	BOOL CommitTR();
	BOOL RollbackTR();

protected:
	BOOL m_bTR;

	VEC_NOTIFY m_aNotify;
	VEC_SCHEMA m_aSchema;
	MAP_SCHEMA m_mSchema;

};