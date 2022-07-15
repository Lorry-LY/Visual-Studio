#include<stdio.h>






int main()
{
	int i=0, j = 0;
	int a[3][3] = { 0 };
	int (*p)[3] = a;
	printf("%d", *((p+i) + j));
	


	return 0;
}