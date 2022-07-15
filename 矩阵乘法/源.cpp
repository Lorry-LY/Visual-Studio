#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

const int N = 101;
long m[N][N] = { 0 };
int s[N][N] = { 0 };
int p[N + 1] = { 0 };

void MatrixChain(int n)
{
	for (int i = 1; i <= n; i++)m[i][i] = 0;
	for (int r = 2; r <= n; r++)
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;
			m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				long temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < m[i][j])
				{
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}
	MatrixChain(n);
	cout << m[1][n];

	return 0;
}
