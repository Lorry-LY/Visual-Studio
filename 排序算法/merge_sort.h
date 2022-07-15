#pragma once

#include<iostream>
#include<vector>
#include<queue>

template<typename T>
void merge(std::vector<T>& arr, int left, int middle, int right);

template<typename T>
void mergeSort_R(std::vector<T>&arr, int left, int right)
{
	if (left == right)return;
	int middle = (left + right) / 2;
	mergeSort_R(arr, left, middle);
	mergeSort_R(arr, middle + 1, right);
	merge(arr, left, middle, right);
}

template<typename T>
void mergeSort_C(std::vector<T>& arr, int left, int right)
{
	if (left == right)return;
	int len = right - left + 1;
	int index = 1;
	while (index<len)
	{
		for (int begin = 0; begin < len; begin += 2 * index)
		{
			int mid = begin + index - 1 < len - 1 ? begin + index - 1 : len - 1;
			int end = begin + 2 * index - 1 < len - 1 ? begin + 2 * index - 1 : len - 1;
			merge(arr, left + begin, left + mid, left + end);
		}
		index *= 2;
	}
}

template<typename T>
void merge(std::vector<T>& arr, int left, int middle, int right)
{
	const int len = right - left + 1;
	T* temp = new T[len];
	int index = 0;
	int i = left;
	int j = middle + 1;
	while (i <= middle && j <= right)temp[index++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
	while (i <= middle)temp[index++] = arr[i++];
	while (j <= right)temp[index++] = arr[j++];
	for (i = 0; i < index; i++)arr[left + i] = temp[i];
	delete[] temp;
}