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
	if (a.first - a.second > b.first - b.second)return false;
	else return true;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a1, a2;
		cin >> a1 >> a2;
		a.push_back({a1,a2 });
	}
	ll Max = 0;
	ll curNum = 0;
	sort(a.begin(), a.end(), cmp);
	while (a.size())
	{
		PII node = a.back();
		a.pop_back();
		if (curNum + node.first > Max)
		{
			Max = curNum + node.first;
		}
		curNum += node.second;
	}
	cout << Max << endl;
	
	


	return 0;
}