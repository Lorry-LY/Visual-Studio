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
		cout << "������󣺶���ϵ��Ϊ0" << endl;
		exit(1);
	}
	//����ʽ���
	
	return 0;
}