#pragma once

class CNotifyObserver
{
public:
	CNotifyObserver();
	virtual ~CNotifyObserver();

public:
	virtual int Notify(UINT uiMsg, WPARAM wParam, LPARAM lParam) = 0;

};

