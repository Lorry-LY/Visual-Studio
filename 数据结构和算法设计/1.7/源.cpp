#include<stdio.h>

int main()
{
	int n = 10000;
	double sum = 0;
	for (int i = n / 2; i <= n; i++)
	{
		sum += 1 / (double)i;
	}
	printf("%f", sum);

	return 0;
}