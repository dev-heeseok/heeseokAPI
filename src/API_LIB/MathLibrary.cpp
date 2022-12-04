#include "pch.h"
#include "MathLibrary.h"

bool util::CMathLibrary::IsZero(double value, double epsilon)
{
	return fabs(value) < epsilon;
}
