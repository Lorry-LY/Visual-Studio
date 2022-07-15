#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[13] = { 1,2,1,2,5,45,788,65,4,5,9,2,45 };
	for (int j = 1; j < sizeof(a)/sizeof(int); j++)
	{
		
		for (int i = j - 1; i > 0; i--)
		{
			if (a[i+1] < a[i])
			{
				int step = a[i+1] + a[i];
				a[i + 1] = step - a[i + 1];
				a[i] = step - a[i];
			}
		}
	}
	for (int i = 0; i < 13; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << sizeof(a) / sizeof(int) << endl;


	return 0;
}