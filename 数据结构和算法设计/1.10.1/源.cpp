#include<iostream>

using namespace std;

int sum(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return (2 * n - 1) + sum(n - 1);
}

int main()
{
	int n = 5;
	if (n * n == sum(5))
	{
		cout<<"证明成功。";
	}
	return 0;
}