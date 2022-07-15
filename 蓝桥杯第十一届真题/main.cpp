#include<iostream>
#include<Windows.h>
using namespace std;






int main()
{
	DWORD start, end;
	start = GetTickCount();
	

	int number = 1;
	int n = 39;
	int a[40][40] = { 0 };
	a[0][0] = 1;
	int x, y;
	y = 1;
	x = -1;
	int step = 1;
	for (int i = 1; i <= 19; i++)
	{
		int j = 0;
		step++;
		for (x++, j = 0; j < step; j++,x++,y--)
		{
			a[x][y] = ++number;
		}
		step++;
		for (y++, j = 0; j < step; j++, y++, x--)
		{
			a[x][y] = ++number;
		}
	}
	
	cout << a[19][19];


	end = GetTickCount()-start;
	cout << endl << end;
	return 0;
}