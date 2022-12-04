#pragma once

class AFX_EXT_CLASS IObserver
{
public:
	IObserver() {}
	virtual ~IObserver() {}

public:
	virtual int Update(UINT uiMsg, WPARAM wParam, LPARAM lParam) = 0;

};
