#include<stdio.h>

int function(int n)
{
	if (n == 2)
	{
		return 2;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return function(n - 1) + function(n - 2);
	}
}

int main()
{
	long long num1 = 0;
	int n = 6;
	for (int i = 1; i <= n - 2; i++)
	{
		num1 += function(i);
	}
	long long num2 = function(n) - 2;
	if (num1 == num2)
	{
		printf("证明成功。\n");
	}
	return 0;
}