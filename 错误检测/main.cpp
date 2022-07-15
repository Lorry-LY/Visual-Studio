#include<iostream>

using namespace std;

int judge(int a, int b, int c)
{
	try
	{
		if (!a)
			throw 'a';
	}
	catch (char)
	{
		throw;
	}
		
}


int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cin.get();
	try
	{
		judge(a, b, c);
	}
	catch (char)
	{
		cout << "输入错误：二次系数为0" << endl;
		exit(1);
	}
	//二项式求根
	
	return 0;
}