#include<iostream>

using namespace std;

template<typename T>
T max(T x[], int n);

int main()
{
	int x[5] = { 1,2,3,4,5 };
	cout<<max(x, 5);

	return 0;
}

template<typename T>
T max(T x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (x[0] < x[i])
		{
			x[0] = x[i] + x[0];
			x[i] = x[0] - x[i];
			x[0] = x[0] - x[i];
		}
	}
	return x[0];
}