//4.cpp

#include<stdio.h>

int main()
{
	int a[7];
	int number = 0;
	printf("������7����ίͶƱ�����1Ϊ�޳ɣ�0Ϊ���ԡ�\n");
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &a[i]);
		if (a[i])number++;
	}
	if (number >= 4)
	{
		printf("����\n");
	}
	else
	{
		printf("δ����\n");
	}
	return 0;
}
