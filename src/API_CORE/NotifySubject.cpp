#include "pch.h"
#include "NotifySubject.h"

#include "../API_LIB/IObserver.h"

CNotifySubject::CNotifySubject()
{
}

CNotifySubject::~CNotifySubject()
{
}

void CNotifySubject::Attach(IObserver* pObserver)
{
	if (pObserver == nullptr)
		return;

	m_aObserver.push_back(pObserver);
}

void CNotifySubject::Detach(IObserver* pObserver)
{
	if (pObserver == nullptr)
		return;

	auto itr = std::find(m_aObserver.cbegin(), m_aObserver.cend(), pObserver);
	if (itr != m_aObserver.cend())
		m_aObserver.erase(itr);
}

void CNotifySubject::Notify(UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
	for (auto pObserver : m_aObserver)
		pObserver->Update(uiMsg, wParam, lParam);
}
