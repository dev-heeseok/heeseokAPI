#pragma once

namespace util
{
	std::string ToStr(const std::wstring& wstr, int codepage = CP_ACP) noexcept
	{
		return std::string(CT2CA(wstr.c_str(), codepage));
	}

	std::wstring ToWStr(const std::string& str, int codepage = CP_ACP) noexcept
	{
		return std::wstring(CA2CT(str.c_str(), codepage));
	}

}

