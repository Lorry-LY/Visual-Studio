#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1011;


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	int** a = new int* [N];
	bool** flag = new bool* [N];
	long** w = new long* [N];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[N];
		flag[i] = new bool[N];
		w[i] = new long[N];
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			flag[i][j] = false;
			w[i][j] = -200000;
		}
	}
	typedef pair<int, int>PII;
	queue<PII>q;
	const int dx[4] = { -1,1,0,0 };
	const int dy[4] = { 0,0,-1,1 };
	q.push({ 0,0 });
	w[0][0] = a[0][0];
	while (q.size())
	{
		PII node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = node.first + dx[i];
			int y = node.second + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m)continue;
			if (w[node.first][node.second] + a[x][y] <= w[x][y])continue;
			w[x][y] = w[node.first][node.second] + a[x][y];
			if (flag[x][y])continue;
			q.push({ x,y });
		}
		flag[node.first][node.second] = true;
	}
	cout << w[n - 1][m - 1];
	


	return 0;
}