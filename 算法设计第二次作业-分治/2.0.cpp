#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int a[1000000 + 1] = { 0 };

int getRand(int left, int right)
{
	srand(time(NULL));
	int number = 0;
	do {
		number = rand() % right;
		number++;
	} while (number < left);
	return number;
}

void swaps(int x, int y)
{
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

int Partition(int left, int right)
{
	int i = left;
	int j = right + 1;
	int x = a[left];
	while (1)
	{
		while (a[++i] < x && i < right);
		while (a[--j] > x);
		if (i >= j)break;
		swaps(j, i);
	}
	a[left] = a[j];
	a[j] = x;
	return j;
}

int quickSort(int left, int right, int k)
{
	if (left < right)
	{
		int handle = Partition(left, right);
		if (handle == right - k + 1)
		{
			return a[handle];
		}
		else if (handle > right - k + 1)
		{
			quickSort(left, handle - 1, k - (right - handle) - 1);
		}
		else
		{
			quickSort(handle + 1, right, k);
		}
	}
	else
	{
		return a[left];
	}

}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	if (!(k > n || k < 1 || n>pow(10, 6)))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		printf("%d", quickSort(0, n - 1, k));
	}



	return 0;
}