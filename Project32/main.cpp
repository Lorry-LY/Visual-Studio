#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
struct point
{
	double x;
	double y;
}p[100];

int main()
{
	FILE* fp;
	if (!(fp = fopen("Point.txt", "r")))
	{
		printf("文件打开失败。\n");
		return 0;
	}
	int len = 0;
	while (fread(&p[len++],sizeof(struct point),1,fp)==1)
	{
		printf("第%d个坐标距离原点的距离为：%.2f\n", len, sqrt(p[len - 1].x * p[len - 1].x + p[len - 1].y * p[len - 1].y));
	}
	fclose(fp);
	return 0;
}