#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int>PII;

vector<PII>a;

bool cmp(PII a, PII b)
{
	if (a.second < b.second)return false;
	else if (a.second == b.second && a.first < b.first)return false;
	else return true;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		while (n--)
		{
			int a1, a2;
			cin >> a1 >> a2;
			a.push_back({ a1,a2 });
		}
		sort(a.begin(), a.end(), cmp);
		int Max = 0;
		int curTime = 0;
		while (a.size())
		{
			PII node = a.back();
			a.pop_back();
			if (node.first < curTime)continue;
			curTime = node.second;
			Max++;
		}
		cout << Max << endl;
		a.clear();
	}
	



	return 0;
}