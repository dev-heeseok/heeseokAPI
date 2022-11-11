#pragma once

#include <vector>

class CNotifyObserver;
class CNotifySubject
{
	using VEC_OBSERVER = std::vector<CNotifyObserver*>;

public:
	CNotifySubject();
	virtual ~CNotifySubject();

public:
	virtual void RegisterObserver(CNotifyObserver* pObserver);
	virtual void UnregisterObserver(CNotifyObserver* pObserver);

	virtual void NotifyObservers(UINT uiMsg, WPARAM wParam = 0, LPARAM lParam = 0);

protected:
	VEC_OBSERVER m_aObservers;

};
