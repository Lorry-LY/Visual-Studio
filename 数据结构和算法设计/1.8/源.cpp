#include<stdio.h>

int main()
{
	int sum = 1;
	for (int i = 1; i <= 5; i++)
	{
		sum *= 2;
		sum %= 10;
	}
	printf("�����Ϊ%d��", sum % 5);

	return 0;
}