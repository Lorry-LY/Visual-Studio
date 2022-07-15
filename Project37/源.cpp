#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>


int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	for (int j = 0; j < n; j++)
	{
		int letter[26] = { 0 };
		char a[50];
		int len = 0;
		while ((a[len++] = getchar()) != '\n');
			for (int i = 0; i < len - 1; i++)
			{
				if ('a' <= a[i] && a[i] <= 'z')
				{
					letter[a[i] - 97]++;

				}
				else if ('A' <= a[i] && a[i] <= 'Z')
				{
					letter[a[i] - 65]++;
				}

			}
		printf("%d %d\n", len - 1, letter[0]);
	}


	return 0;
}