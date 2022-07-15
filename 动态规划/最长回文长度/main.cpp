

#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
	if (s.length() < 1)return "";
	string str = "#";
	for (int i = 0; i < s.length(); i++)
	{
		str += s[i];
		str += "#";
	}	
	const int len = str.length();
	int MaxRight = 0;				// 当前访问到的所有回文子串，所能触及的最右一个字符的位置
	int pos = 0;					// MaxRight对应的回文串的对称轴所在的位置
	int MaxRL = 0;					// 最大回文串的回文半径
	int MaxPos = 0;					// MaxRL对应的回文串的对称轴所在的位置
	vector<int>RL(len);
	for (int i = 0; i < str.length(); i++)
	{
		if (i < MaxRight)
		{// 1) 当i在MaxRight的左边
			RL[i] = min(RL[2 * pos - i], MaxRight - i);
		}
		else
		{// 2) 当i在MaxRight的右边
			RL[i] = 1;
		}

		while (i - RL[i] >= 0  // 可以把RL[i]理解为左半径,即回文串的起始位不能小于0
			&& i + RL[i] < len // 同上,即回文串的结束位不能大于总长
			&& str[i - RL[i]] == str[i + RL[i]]// 回文串特性，左右扩展，判断字符串是否相同
			)
		{
			RL[i] += 1;
		}

		// 更新MaxRight, pos
		if (RL[i] + i - 1 > MaxRight)
		{
			MaxRight = RL[i] + i - 1;
			pos = i;
		}

		// 更新MaxRL, MaxPos
		if (MaxRL <= RL[i])
		{
			MaxRL = RL[i];
			MaxPos = i;
		}


	}
	return s.substr((MaxPos - MaxRL + 1) / 2, MaxRL - 1);
}

int main()
{
	cout<<longestPalindrome("babad");


	return 0;
}