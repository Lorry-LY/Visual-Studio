#include<stdio.h>
#include<math.h>
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
	return function(n - 1) + function(n - 2);
}

int main()
{

	for (int i = 0; i < 10; i++)
	{
		int num1 = function(i+1);
		double num2 = pow((1 + sqrt(5)) / 2, i + 1);
		if (num1 < num2)
		{
			printf("n=%d验证成功。\n", i + 1);
		}
	}
	return 0;
}