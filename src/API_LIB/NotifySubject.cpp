#include "pch.h"
#include "NotifySubject.h"
#include "NotifyObserver.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CNotifySubject::CNotifySubject()
{
}

CNotifySubject::~CNotifySubject()
{
}

void CNotifySubject::RegisterObserver(CNotifyObserver* pObserver)
{
	if (pObserver == nullptr)
		return;

	auto itr = std::find(m_aObservers.cbegin(), m_aObservers.cend(), pObserver);
	if (itr != m_aObservers.cend())
	{
		ASSERT(FALSE);

		// TODO. duplicated
		m_aObservers.erase(itr);
	}

	m_aObservers.push_back(pObserver);
}

void CNotifySubject::UnregisterObserver(CNotifyObserver* pObserver)
{
	if (pObserver == nullptr)
		return;
	
	auto itr = std::find(m_aObservers.cbegin(), m_aObservers.cend(), pObserver);
	if (itr != m_aObservers.cend())
		m_aObservers.erase(itr);
}

void CNotifySubject::NotifyObservers(UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
	for (auto pObserver : m_aObservers)
	{
		if (int res = pObserver->Notify(uiMsg, wParam, lParam))
		{
			ASSERT(FALSE);
			return;
		}
	}
}
