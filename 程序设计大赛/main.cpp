#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 50;


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	while (n != 0 || m != 0)
	{
		int a[N][N] = { 0 };
		bool flag[N][N] = { false };
		int w[N][N] = { 0 };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		typedef pair<int, int>PII;
		queue<PII>top;
		queue<PII>q;
		const int dx[4] = { -1,1,0,0 };
		const int dy[4] = { 0,0,-1,1 };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int number = 0;
				int flow = 0;
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < 0 || x >= n || y < 0 || y >= m)
					{
						flow++;
						continue;
					}
					if (a[x][y] < a[i][j])number++;
				}
				if (number + flow == 4)
				{
					top.push({ i,j });
				}
			}
		}
		int sum = 0;
		if (top.size())
		{
			while (top.size())
			{
				PII head = top.front();
				top.pop();
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						flag[i][j] = false;
						w[i][j] = 0;
					}
				}
				q.push(head);
				w[head.first][head.second] = 0;
				while (q.size())
				{
					PII node = q.front();
					q.pop();
					int wnumber = 0;
					for (int i = 0; i < 4; i++)
					{
						int x = node.first + dx[i];
						int y = node.second + dy[i];
						if (x < 0 || x >= n || y < 0 || y >= m)continue;
						if (a[x][y] >= a[node.first][node.second])continue;
						if (w[x][y] > w[node.first][node.second])
						{
							wnumber++;
							continue;
						}
						w[x][y] = w[node.first][node.second] + 1;
						if (wnumber==4)continue;
						q.push({ x,y });
					}
					//flag[node.first][node.second] = true;
				}
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						if (w[i][j] > sum)sum = w[i][j];
					}
				}
			}
		}
		cout << sum << endl;
		scanf("%d %d", &n, &m);
		getchar();
	}





	return 0;
}