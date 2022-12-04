#pragma once

namespace util
{
	class AFX_EXT_CLASS CMathLibrary
	{
	public:
		static bool IsZero(double value, double epsilon = DBL_EPSILON);

	};
}

