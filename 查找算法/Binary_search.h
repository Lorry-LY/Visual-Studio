#pragma once

#include <iostream>
#include <vector>

template<typename T>
int binarySearch_R(const std::vector<T>arr, int low, int high, const T& target)
{
	int middle = (low + high) / 2;
	if (low > high)return -1;
	if (arr[middle] == target)return middle;
	else if (arr[middle] > target)
	{
		return binarySearch_R(arr, low, middle - 1, target);
	}
	else if (arr[middle] < target)
	{
		return binarySearch_R(arr, middle + 1, high, target);
	}
}

template<typename T>
int binarySearch_C(const std::vector<T>arr, int low, int high, const T& target)
{
	while (low < high)
	{
		int middle = (low + high) / 2;
		if (arr[middle] == target)
		{
			return middle;
		}
		else if (arr[middle] > target)
		{
			high = middle - 1;
		}
		else if (arr[middle] < target)
		{
			low = middle + 1;
		}
	}
	return -1;
}
