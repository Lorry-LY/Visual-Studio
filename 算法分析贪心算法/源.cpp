#include<iostream>

using namespace std;

const int N = 10000;
int a[26] = { 0 };
int b[26] = { 0 };
int w[26] = { 0 };

int findMax()
{
	int number = 0;
	int k = -1;
	for (int i = 0; i < 26; i++)
	{
		if (a[i])
		{
			if (a[i] > number)
			{
				number = a[i];
				k = i;
			}
		}
	}
	b[k] = a[k];
	a[k] = 0;
	return k;
}

int main()
{
	char ch;
	while ((ch=getchar())!='\n')
	{
		a[ch - 'a']++;
	}
	int number;
	int weight = 26;
	while ((number=findMax())!=-1)
	{
		w[number] = weight--;
	}
	long sum = 0;
	for (int i = 0; i < 26; i++)
	{
		sum += b[i] * w[i];
	}
	cout << sum << endl;

	return 0;
}
