#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>

using namespace std;

const int N = 1001;
char a[N] = { 0 };
char b[N] = { 0 };
int c[2][N] = { 0 };

int min(int t1, int t2, int t3)
{
	if (t1 < t2)
	{
		return t1 < t3 ? t1 : t3;
	}
	else return t2 < t3 ? t2 : t3;
}

int MaxChain(int len1, int len2)
{
	if (len1 != 1)
	{
		for (int i = 0; i <= len2; i++)
		{
			c[0][i] = i;
			//cout << c[0][i] << " ";
		}
		//cout << endl;

		for (int i = 1; i <= len1; i++)
		{
			c[i % 2][0] = i;
			//cout << i << " ";
			for (int j = 1; j <= len2; j++)
			{
				int t1 = c[i % 2][j - 1] + 1;
				int t2 = c[i % 2 ? 0 : 1][j] + 1;
				int t3;
				if (a[i - 1] == b[j - 1])
				{
					t3 = c[i % 2 ? 0 : 1][j - 1];
				}
				else t3 = c[i % 2 ? 0 : 1][j - 1] + 1;
				c[i % 2][j] = min(t1, t2, t3);
				//cout << c[i % 2][j] << " ";
			}
			//cout << endl;
		}
		//cout << len1 << len2 << endl;
		return c[len1 % 2][len2];
	}
	else
	{
		for (int i = 0; i < len2; i++)
		{
			if (a[0] == b[i])return len2 - 1;
		}
		return len2;
	}

}


int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	for (int i = 0; i < T; i++)
	{
		int len1, len2;
		len1 = len2 = 0;
		while ((a[len1++] = getchar()) != '\n');
		while ((b[len2++] = getchar()) != '\n');
		len1--; len2--;
		cout << MaxChain(len1, len2) << endl;
		//cout << (len1 < len2 ? len2 - number : len1 - number) << endl;
	}
	return 0;
}
