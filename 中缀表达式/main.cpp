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
		cout << "��������Ľ��Ϊ��" << endl;
		z.PreOrderTraverse(z.getRoot());
		cout << endl;
		cout << "ǰ������Ľ��Ϊ��" << endl;
		z.FrontOrderTraverse(z.getRoot());
		cout << endl;
		printf("���Ϊ:%.2lf\n", z.getResult(z.getRoot()));
	}
	
	
	return 0;
}