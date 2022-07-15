#pragma once

#include <iostream>
#include<vector>

/*
�������arr�߼��Ͼ���һ���ѡ�

���������ǿ��Եó��������ʣ��ص㣩

���ڴ󶥶ѣ�arr[i] >= arr[2i + 1] && arr[i] >= arr[2i + 2]

����С���ѣ�arr[i] <= arr[2i + 1] && arr[i] <= arr[2i + 2]
*/

template<typename T>
void display(std::vector<T>& arr, int low, int high);

template<typename T>
void swap(T& x, T& y);

template<typename T>
void down(std::vector<T>& arr, int low, int high, int index);

template<typename T>
void buildHeap(std::vector<T>& arr, int low, int high);

template<typename T>
void heapSort(std::vector<T>& arr, int low, int high)
{
	int size = high - low + 1;
	printf("��ʼ������:");
	buildHeap(arr, low, high);
	display(arr, low, high);
	for (int i = size - 1; i > 0; i--)
	{
		swap(arr[low], arr[low + i]);
		down(arr, low, low + i - 1, 0);
		printf("����������:");
		display(arr, low, high);
	}

}

template<typename T>
void heapSort(std::vector<T>& arr, int low, int high, int k)		//Ѱ�ҵ�K���Ԫ��;
{
	int size = high - low + 1;
	buildHeap(arr, low, high);
	for (int i = size - 1; k > 1; i--, k--)
	{
		swap(arr[low], arr[low + i]);
		down(arr, low, low + i - 1, 0);
	}
	// return arr[0];

}

template<typename T>
void buildHeap(std::vector<T>& arr, int low, int high)
{
	int size = high - low + 1;
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		down(arr, low, high, i);
	}
}

template<typename T>
void down(std::vector<T>& arr, int low, int high, int index)
{
	int size = high - low + 1;
	int parent = index;
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + low] < arr[child + 1 + low])child++;
		if (arr[parent + low] < arr[child +low])
		{
			swap(arr[parent + low], arr[child + low]);
			parent = child;
		}
		child = child * 2 + 1;
	}
}


template<typename T>
void swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}


template<typename T>
void display(std::vector<T>& arr, int low, int high)
{
	for (int i = low; i <= high; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}