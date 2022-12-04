#pragma once

#include "NotifyDefine.h"

#include "../API_LIB/ISubject.h"

class AFX_EXT_CLASS CNotifySubject : public ISubject
{
	using VEC_OBSERVER = std::vector<IObserver*>;

public:
	CNotifySubject();
	virtual ~CNotifySubject();

public:
	virtual void Attach(IObserver* pObserver) override;
	virtual void Detach(IObserver* pObserver) override;
	virtual void Notify(UINT uiMsg, WPARAM wParam, LPARAM lParam) override;

protected:
	VEC_OBSERVER m_aObserver;

};

