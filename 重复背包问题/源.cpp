#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

const int N = 1000;
int w[50][50001] = { 0 };
int m[50] = { 0 };
int s[50] = { 0 };

int main()
{
	int T;
	scanf("%d", &T);
	for (int d = 0; d < T; d++)
	{
		int n, v;
		scanf("%d %d", &n, &v);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%f", &s[i]);
		}
		for (int j = 0; j <= v; j++)
		{
			if (j < s[n - 1])w[n - 1][j] = 0;
			else w[n - 1][j] = m[n - 1] * (j / s[n - 1]);
		}
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j <= v; j++)
			{
				if (j < s[i])w[i][j] = w[i + 1][j];
				else
				{
					int t1 = w[i + 1][j];
					int t2 = w[i][j - s[i]] + m[i];
					int t3 = w[i + 1][j - s[i]] + m[i];
					if (t1 < t2)
					{
						if (t2 < t3)
						{
							w[i][j] = t3;
						}
						else
						{
							w[i][j] = t2;
						}
					}
					else
					{
						if (t1 < t3)
						{
							w[i][j] = t3;
						}
						else
						{
							w[i][j] = t1;
						}
					}
				}
			}
		}
		cout << w[0][v] << endl;
	}



	return 0;
}
