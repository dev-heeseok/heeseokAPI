#pragma once

class AFX_EXT_CLASS CNotifyObserver
{
public:
	CNotifyObserver();
	virtual ~CNotifyObserver();

public:
	virtual int Notify(UINT uiMsg, WPARAM wParam, LPARAM lParam) = 0;

};

