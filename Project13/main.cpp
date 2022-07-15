#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define ISLETTER_P (('a'<=str[p]&&str[p]<='z')||('A'<=str[p]&&str[p]<='Z'))
#define ISLETTER_Q (('a'<=str[q]&&str[q]<='z')||('A'<=str[q]&&str[q]<='Z'))

void reserve(char* str, int p, int q)
{
	if (p == q - 1)return;
	char temp[15] = { '\0' };
	for (int i = 0; i < q - p; i++)
	{
		temp[i] = str[p + i];
	}
	for (int i = q - p - 1; i >= 0; i--)
	{
		str[q - i - 1] = temp[i];
	}
	return;
}


int main()
{
	char str[100] = { '\0' };
	int len = 0;
	while ((str[len] = getchar()) != '\n')len++;
	//str[len]='\0';
	int p = 0, q = 0;
	while (p!=len)
	{
		while (!ISLETTER_P)p++;
		q = p;
		while (ISLETTER_Q)q++;
		reserve(str, p, q);
		p = q;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}


	return 0;
}