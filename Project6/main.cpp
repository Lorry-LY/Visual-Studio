#include <stdio.h>
int Leapyear(int year)
{
	if (year < 1990)
		printf("输入日期错误:\n");
	return((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0;
}
int CountDay(int year, int month, int day)
{
	int count = 0, eyear;
	for (eyear = 1990; eyear < year; eyear++)
	{
		if (Leapyear(year) == 1)
			count = count + 366;
		else
			count = count + 365;
	}
	int num[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }, y;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		num[2] += 1;
	for (y = 1; y < month; y++)
	{
		count += num[y];
	}
	count += day;
	return count;
}
int main()
{
	int year, month, day, count;
	printf("请输入正确的年月日:xxxx xx xx\n");
	scanf("%d %d %d", &year, &month, &day);
	Leapyear(year);
	count=CountDay(year, month, day);
	if (count % 5 > 0 && count % 5 < 4)
		printf("今天打鱼\n");
	else
		printf("今天晒网\n");
	return 0;
}