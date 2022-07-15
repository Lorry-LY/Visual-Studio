#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

const int N = 201;
const int M = 101;
float p[M] = { 0.0 };
float c[N][M] = { 0.0 };

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)scanf("%f", &p[i]);
	c[0][0] = 1 - p[0];
	c[0][1] = p[0];
	for (int i = 2; i <= k; i++)c[0][i] = 0;
	for (int i = 1; i < n; i++)
	{
		c[i][0] = (1 - p[i]) * c[i - 1][0];
		for (int j = 1; j <= k; j++)c[i][j] = c[i - 1][j - 1] * p[i] + (1 - p[i]) * c[i - 1][j];
	}
	float result = c[n - 1][k] +0.00005;
	printf("%.4f", result);

	return 0;
}