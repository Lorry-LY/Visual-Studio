#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;


int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	int a[1000] = { 0 };
	int deep = 1;
	int Max = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		getchar();
	}
	for (int i = 1; i <= ceil(log2(n)); i++)
	{
		int sum = 0;
		for (int j = pow(2, i - 1); j < pow(2, i); j++)
		{
			sum += a[j - 1];
		}
		if (sum > Max)
		{
			Max = sum;
			deep = i;
		}
	}
	cout << deep << endl;


	return 0;
}