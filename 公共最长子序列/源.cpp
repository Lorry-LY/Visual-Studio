#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

const int N = 1000;
int a[N] = { 0 };
int b[N] = { 0 };
int c[N][N] = { 0 };

int MaxChain(int n)
{
	int length = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[0] == b[i])c[0][i] = 1;
		else c[0][i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (b[0] == a[i])c[i][0] = 1;
		else c[i][0] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (a[i] == b[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] < c[i][j - 1])
			{
				c[i][j] = c[i][j - 1];
			}
			else
			{
				c[i][j] = c[i - 1][j];
			}
		}
	}

	return c[n - 1][n - 1];
}


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	cout << MaxChain(n);


	return 0;
}
