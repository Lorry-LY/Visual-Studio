#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "ZhongZhui.h"

int main()
{
	system("color FC");
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_)
	string str;
	while (cin>>str)
	{
		ZhongZhui z(str);
		cout << "中序遍历的结果为：" << endl;
		z.PreOrderTraverse(z.getRoot());
		cout << endl;
		cout << "前序遍历的结果为：" << endl;
		z.FrontOrderTraverse(z.getRoot());
		cout << endl;
		printf("结果为:%.2lf\n", z.getResult(z.getRoot()));
	}
	
	
	return 0;
}