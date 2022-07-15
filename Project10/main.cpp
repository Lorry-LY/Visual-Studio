#include<iostream>

#include<vector>

using namespace std;

int getout(int n, int m)
{
	vector<int>monkey;
	for (int i = 1; i <= n; i++)
	{
		monkey.push_back(i);
	}
	for (int number = 0; monkey.size() != 1;)
	{
		number = (number + m - 1) % monkey.size();
		monkey.erase(monkey.begin() + number);
	}
	return monkey.back();
}

int main()
{
	int n, m;
	cout << "请输入参加猴王选举的猴子数和报数最大值：";
	cin >> n >> m;
	cout<<"本届猴王是："<<getout(n, m);

	return 0;
}