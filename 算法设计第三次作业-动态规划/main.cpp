#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 200000;

int a[N] = { 0 };
int b[N] = { 0 };

void getMax(int n)
{
	if (n == 0)return;
	getMax(n - 1);
	
}


int main()
{
	int n;
	scanf("%d", &n);
	scanf("%d", &a[0]);
	b[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = b[i - 1] + a[i] > a[i] ? b[i - 1] + a[i] : a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (b[0] < b[i])
		{
			long temp = b[0];
			b[0] = b[i];
			b[i] = temp;
		}
	}
	cout << b[0];

	return 0;
}