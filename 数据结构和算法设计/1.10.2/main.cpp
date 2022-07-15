#include<iostream>

using namespace std;

int squre(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * n * n + squre(n - 1);
}

int sum(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n + sum(n - 1);
}

int main()
{
	int n = 5;
	int i = sum(5);
	if (squre(5) == i * i)
	{
		cout << "证明完成.";
	}
	return 0;
}