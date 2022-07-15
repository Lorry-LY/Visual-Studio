#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

vector<int>stack;
vector<int>output;

int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	if (1 <= T && T <= 10)
	{
		output.push_back(0);
		for (int m = 0; m < T; m++)
		{
			int n;
			scanf("%d", &n);
			getchar();
			for (int j = 0; j < n; j++)
			{
				int temp;
				scanf("%d", &temp);
				stack.push_back(temp);
				getchar();
				while (stack.empty()||stack.back() == output.back() + 1 || stack.front() == output.back() + 1)
				{
					if (stack.empty())
					{
						break;
					}
					else if (stack.back() == output.back() + 1)
					{
						temp = stack.back();
						stack.pop_back();
						output.push_back(temp);
					}
					else
					{
						temp = stack.front();
						stack.erase(stack.begin());
						output.push_back(temp);
					}
				}
			}
			if (stack.empty())
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}

			stack.clear();
			output.clear();
			output.push_back(0);
		}
	}
	



	return 0;
}