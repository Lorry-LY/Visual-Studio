#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

const int N = 100000;
int a[N] = { 0 };
int b[N] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%d", &a[0]);
	for (int j = 0; j < n; j++)b[j] = 1;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a[i]);
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				if (b[i] <= b[j])
				{
					b[i] = b[j] + 1;
				}
			}
		}
	}
	for (int j = 1; j < n; j++)
	{
		if (b[0] < b[j])
		{
			int temp = b[0];
			b[0] = b[j];
			b[j] = temp;
		}
	}
	cout << b[0];

	return 0;
}
