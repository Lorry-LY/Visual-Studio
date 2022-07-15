#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

//typedef pair<int, int >PII;  //映射
//queue<PII>q;	//队列
//const int N = 1010;		//矩阵最大
//int a[N][N];	//迷宫
//PII pre[N][N];	//pre[i][j]={x,y}:表示从x,y这个点到大i,j这个点
//int dx[] = { 0,-1,0,1 };	//左，上，右，下
//int dy[] = { -1,0,1,0 };
//int n;
//
//void bfs(int x, int y)
//{
//	q.push({ x,y });
//	memset(pre, -1, sizeof pre);
//	while (q.size())
//	{
//		PII node = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int tx = node.first + dx[i];
//			int ty = node.second + dy[i];
//			if (tx < 0 || tx >= n || ty < 0 || ty >= n)continue;
//			if (a[tx][ty])continue;
//			if (pre[tx][ty].first != -1)continue;
//			q.push({ tx,ty });
//			pre[tx][ty] = node;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//
//	bfs(n - 1, n - 1);
//	PII end = { 0,0 };
//	while (true)
//	{
//		printf("%d %d\n", end.first, end.second);
//		if (end.first == n - 1 && end.second == n - 1)break;
//		end = pre[end.first][end.second];
//	}
//
//
//
//	return 0;
//}

typedef pair<int, int>PII;
const int N=1011;

PII** bfs(int** a, int n, int m, int endx, int endy)
{
	PII** per = new PII * [N];
	for (int i = 0; i < N; i++)
	{
		per[i] = new PII[N];
		for (int j = 0; j < N; j++)
		{
			per[i][j] = { -1,-1 };
		}
	}
	const int dx[4] = { 1,-1,0,0 };
	const int dy[4] = { 0,0,-1,1 };
	queue<PII>p;
	p.push({ endx,endy });
	while (!p.empty())
	{
		PII node = p.front();
		p.pop();
		for (int  i = 0; i < 4; i++)
		{
			int x = node.first + dx[i];
			int y = node.second + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m)continue;
			if (per[x][y].first != -1)continue;
			if (a[x][y])continue;
			per[x][y] = { node.first,node.second };
			p.push({ x,y });
		}
		
	}
	return per;
}

void display(int distance)
{
	switch (distance)
	{
	case -1:
		printf("L");
		break;
	case 1:
		printf("R");
		break;
	case -10:
		printf("U");
		break;
	case 10:
		printf("D");
		break;
	default:
		break;
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	int** a = new int * [N];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[N];
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	PII** per = bfs(a, n, m, n - 1, m - 1);
	PII node = per[0][0];
	int distance = node.first * 10 + node.second;
	display(distance);
	while (node.first != n - 1 || node.second != m - 1)
	{
		int x = node.first;
		int y = node.second;
		node = per[x][y];
		distance = (node.first - x) * 10 + (node.second - y);
		display(distance);
	}
	

	return 0;
}