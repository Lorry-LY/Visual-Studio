#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>a;

int main()
{
	int T;
	scanf("%d", &T);
	for (int k = 0; k < T; k++)
	{
		a.clear();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);
			a.push_back(temp);
		}
		sort(a.begin(), a.end());
		long long sum = 0;
		for (int i = 0; i < a.size(); i++)
		{
			sum += (n - i - 1) * a[i];
		}
		cout << sum << endl;
	}


	return 0;
}