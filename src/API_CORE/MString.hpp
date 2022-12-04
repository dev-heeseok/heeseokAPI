#pragma once

template <int N_SIZE>
struct tagString
{
	TCHAR str[N_SIZE];

	tagString()
	{
		str[0] = NULL;
	}
	tagString(const CString& cstr)
	{
		_tcsncpy_s(str, N_SIZE, (LPCTSTR)cstr, _tcslen(cstr));
	}
	tagString(LPCTSTR lpcstr)
	{
		_tcsncpy_s(str, N_SIZE, lpcstr, _tcslen(lpcstr));
	}
	tagString& operator=(const CString cstr)
	{
		_tcsncpy_s(str, N_SIZE, (LPCTSTR)cstr, _tcslen(cstr));
		return *this;
	}
	tagString& operator=(LPCTSTR lpcstr)
	{
		_tcsncpy_s(str, N_SIZE, (LPCTSTR)lpcstr, _tcslen(lpcstr));
		return *this;
	}
	bool operator==(const tagString& tstr) const
	{
		return _tcscmp(str, tstr.str) == 0 ? true : false;
	}
	bool operator==(const CString& cstr) const
	{
		return _tcscmp(str, (LPCTSTR)cstr) == 0 ? true : false;
	}
	bool operator==(LPCTSTR lpszStr) const
	{
		return _tcscmp(str, lpszStr) == 0 ? true : false;
	}
	bool operator!=(const tagString& tstr) const
	{
		return _tcscmp(str, tstr.str) != 0 ? true : false;
	}
	bool operator!=(const CString& cstr) const
	{
		return _tcscmp(str, (LPCTSTR)cstr) != 0 ? true : false;
	}
	bool operator!=(LPCTSTR lpszStr) const
	{
		return _tcscmp(str, lpszStr) != 0 ? true : false;
	}
	int GetLength() const
	{
		return (int)_tcslen(str);
	}
	bool IsEmpty() const
	{
		return GetLength() == 0;
	}
	operator LPCTSTR() const
	{
		return (LPCTSTR)str;
	}
};

using MShortString = tagString<32>;
using MString = tagString<64>;
using MLongString = tagString<128>;
using MPathString = tagString<260>;
using MLongPathString = tagString<512>;
using MLargeString = tagString<1024>;