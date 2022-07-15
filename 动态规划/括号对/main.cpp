#include<iostream>
#include <vector>
using namespace std;


int longestValidParentheses(string s) {
	vector<int>dp(s.length());
	int max = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')dp[i] = 0;
		else
		{
			if (i == 0) {
				dp[i] == 0;
				continue;
			}
			if (s[i - 1] == '(')
			{
				dp[i] = i - 2 < 0 ? 2 : dp[i - 2] + 2;
			}
			else
			{
				dp[i] = i - dp[i - 1] - 2 < 0 ? dp[i - 1] + 2 : dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
			}
			if (dp[i] > max) {
				max = dp[i];
			}
			
		}
	}
	return max;
}



int main()
{
	cout<<longestValidParentheses(")()())");
	return 0;
}