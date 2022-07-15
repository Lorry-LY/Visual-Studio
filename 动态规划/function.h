#pragma once

template<typename T>
T min(const T a, const T b)
{
	return a < b ? a : b;
}

template<typename T>
T min(const T a, const T b,const T c)
{
	if (a < b)
	{
		return a < c ? a : c;
	}
	else
	{
		return b < c ? b : c;
	}
}
