#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int find(int m, int n)
{
	if (m == 0)
	{
		return 1;
	}
	if (n == 0)
	{
		return 0;
	}
	for (int i = m; i >= 0; i--)
	{
		find(m - i, n - 1);
	}

}


int main()
{
	int m, n;
	while (scanf("%d %d", &m,&n) != EOF)
	{
		cout << find(m, n) << endl;
	}

	return 0;
}