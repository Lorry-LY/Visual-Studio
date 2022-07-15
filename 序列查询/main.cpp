#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int A[201] = { 0 };
	int maxNumber = 0, Alen = 0;
	cin >> Alen >> maxNumber;
	for (int i = 1; i <= Alen; i++)
	{
		cin >> A[i];
	}
	long long sum = 0;
	for (int k = 0; k < Alen; k++)
	{
		int left = A[k];
		int right = A[k + 1];
		sum += k * (right - left);
	}
	sum += Alen * (maxNumber - A[Alen]);
	cout << sum;


	return 0;
}