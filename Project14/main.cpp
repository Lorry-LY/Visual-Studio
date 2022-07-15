#include<iostream>
#include<math.h>
using namespace std;

int hang(int** p, int n)
{
	int sum = 0;
	for (int k = 0; k < n; k++)
	{
		int mul = 1;
		for (int i = 0,j=k; i < n; i++,j++)
		{
			mul *= p[i][j % n];
		}
		sum += pow(-1,k)*mul;
	}
		return sum;
	
}


int main()
{
	int n;
	cin >> n;
	int **p=new int*[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = new int[n];
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> p[i][j];
	/*for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << p[i][j];*/
	cout<< hang(p, n);

	return 0;
}