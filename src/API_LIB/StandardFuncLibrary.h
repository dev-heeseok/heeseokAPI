#pragma once

namespace util
{
	template <typename T>
	constexpr auto EnumIndex(T enumerator) noexcept
	{
		return static_cast<std::underlying_type_t<T>>(enumerator);
	}

}