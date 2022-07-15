

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
	int MaxRight = 0;				// ��ǰ���ʵ������л����Ӵ������ܴ���������һ���ַ���λ��
	int pos = 0;					// MaxRight��Ӧ�Ļ��Ĵ��ĶԳ������ڵ�λ��
	int MaxRL = 0;					// �����Ĵ��Ļ��İ뾶
	int MaxPos = 0;					// MaxRL��Ӧ�Ļ��Ĵ��ĶԳ������ڵ�λ��
	vector<int>RL(len);
	for (int i = 0; i < str.length(); i++)
	{
		if (i < MaxRight)
		{// 1) ��i��MaxRight�����
			RL[i] = min(RL[2 * pos - i], MaxRight - i);
		}
		else
		{// 2) ��i��MaxRight���ұ�
			RL[i] = 1;
		}

		while (i - RL[i] >= 0  // ���԰�RL[i]���Ϊ��뾶,�����Ĵ�����ʼλ����С��0
			&& i + RL[i] < len // ͬ��,�����Ĵ��Ľ���λ���ܴ����ܳ�
			&& str[i - RL[i]] == str[i + RL[i]]// ���Ĵ����ԣ�������չ���ж��ַ����Ƿ���ͬ
			)
		{
			RL[i] += 1;
		}

		// ����MaxRight, pos
		if (RL[i] + i - 1 > MaxRight)
		{
			MaxRight = RL[i] + i - 1;
			pos = i;
		}

		// ����MaxRL, MaxPos
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