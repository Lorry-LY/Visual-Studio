#include<iostream>
using namespace std;

int m;
void t_move(int n, char one, char two, char three);
void move(char x, char y);

int main()
{
	cout << "ÇëÊäÈëººÂÞËþµÄ½×Êý£º";
	cin >> m;
	t_move(m,'X', 'Y', 'Z');
	return 0;
}

void t_move(int n, char one, char two, char three)
{
	if (n == 1)
	{
		move(one, three);
	}
	else
	{
		t_move(n - 1, one, three, two);
		move(one, three);
		t_move(n - 1, two, one, three);
	}
}

void move(char x, char y)
{
	cout << x <<"->" << y  << endl;
}