#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

template<typename T>
void quickSort_R(std::vector<T>& arr, int low, int high)
{
	if (low < high)
	{
		int i = low, j = high;
		T target = arr[i];
		while (i<j)
		{
			while (i < j && arr[j] >= target)j--;
			if (i < j)arr[i++] = arr[j];
			while (i < j && arr[i] <= target)i++;
			if (i < j)arr[j--] = arr[i];
		}
		arr[i] = target;
		quickSort_R(arr, low, i - 1);
		quickSort_R(arr, i + 1, high);
	}
}

template<typename T>
void quickSort_C(std::vector<T>& arr, int low, int high)
{
	if (low < high)
	{
		std::vector<std::pair<int, int>>index;
		index.push_back({ low,high });
		while (index.size())
		{
			low = index.back().first;
			high = index.back().second;
			index.pop_back();
			int i = low, j = high;
			T target = arr[i];
			while (i < j)
			{
				while (i < j && arr[j] >= target)j--;
				if (i < j)arr[i++] = arr[j];
				while (i < j && arr[i] <= target)i++;
				if (i < j)arr[j--] = arr[i];
			}
			arr[i] = target;
			if (low < i - 1) {
				index.push_back({ low,i - 1 });
			}
			if (i + 1 < high) {
				index.push_back({ i + 1,high });
			}
		}
	}

}