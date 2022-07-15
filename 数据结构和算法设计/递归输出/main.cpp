#include<stdio.h>
#include<math.h>
void PrintOut(long long int n)
{
	if (abs(n) >= 10)
	{
		PrintOut(n / 10);
	}
	if (abs(n) < 10)
	{
		printf("%d", n % 10);
	}
	else
	{
		printf("%d", abs(n) % 10);
	}
}

int main()
{
	long long int n = -1354;
	PrintOut(n);

	return 0;
}