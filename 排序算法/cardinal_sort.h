#pragma once

#include <iostream>
#include <queue>
#include <vector>

void cardinalSort(std::vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		std::queue<int> bucket[10];
		int cardinal = 10;
		bool ret = true;
		while (ret)
		{
			for (int i = low; i <= high; i++)
			{
				bucket[(arr[i] % cardinal) / (cardinal / 10)].push(arr[i]);
			}
			if (bucket[0].size() == high - low + 1) {
				ret = false;
			}
			int index = 0;
			for (int i = 0; i < 10; i++)
			{
				while (bucket[i].size())
				{
					int temp = bucket[i].front();
					bucket[i].pop();
					arr[index++] = temp;
				}
			}
			cardinal *= 10;
		}
	}
	
}

