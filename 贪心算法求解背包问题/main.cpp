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
	if ((1.0 * a.first / a.second) >= (1.0 * b.first / b.second))return false;
	else return true;
}

int main()
{
	int M, n;
	cin >> M >> n;
	while (n--)
	{
		int a1, a2;
		cin >> a1 >> a2;
		a.push_back({ a1,a2 });
	}
	float curV = 0;
	int curW = 0;
	sort(a.begin(), a.end(), cmp);
	while (a.size())
	{
		PII PII = a.back();
		a.pop_back();
		if (curW + PII.second <= M)
		{
			curV += PII.first;
			curW += PII.second;
		}
		else
		{
			curV += PII.first*((M-curW)/(1.0*PII.second));
			curW = M;
		}
	}
	printf("%.3f\n", curV);

	return 0;
}