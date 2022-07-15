//4.cpp

#include<stdio.h>

int main()
{
	int a[7];
	int number = 0;
	printf("请输入7个评委投票结果，1为赞成，0为反对。\n");
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &a[i]);
		if (a[i])number++;
	}
	if (number >= 4)
	{
		printf("晋级\n");
	}
	else
	{
		printf("未晋级\n");
	}
	return 0;
}
