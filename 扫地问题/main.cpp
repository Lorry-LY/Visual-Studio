#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int>PII;

vector<PII>a;
queue<PII>b;


bool cmp(PII a, PII b)
{
	if (a.first < b.first)return false;
	else if (a.first == b.first && a.second > b.second)return false;
	else return true;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int m, n;
		cin >> m >> n;
		while (m--)
		{
			int a1, a2;
			cin >> a1 >> a2;
			a.push_back({ a1,a2 });
		}
		sort(a.begin(), a.end(), cmp);
		bool isCan = false;
		int i = 1;
		int Max = 0;
		while (a.size())
		{
			PII node = a.back();
			a.pop_back();
			if (node.first > i + 1)break;
			if (node.second <= i)continue;
			i = node.second;
			Max++;
			if (i >= n)
			{
				isCan = true;
				break;
			}
		}
		if (isCan)cout << Max << endl;
		else cout << -1 << endl;
		a.clear();
	}




	return 0;
}