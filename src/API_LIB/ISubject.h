#pragma once

class IObserver;
class AFX_EXT_CLASS ISubject
{
public:
	ISubject() {}
	virtual ~ISubject() {}

public:
	virtual void Attach(IObserver* pObserver) = 0;
	virtual void Detach(IObserver* pObserver) = 0;
	virtual void Notify(UINT uiMsg, WPARAM wParam, LPARAM lParam) = 0;

};
