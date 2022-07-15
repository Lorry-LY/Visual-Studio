
#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<string, int,less<string> >c;
	c.insert(make_pair("zero", 0));
	c.insert(make_pair("one", 1));
	c.insert(make_pair("two", 2));
	c.insert(make_pair("three", 3));
	c.insert(make_pair("fore", 4));
	c.insert(make_pair("five", 5));
	c.insert(make_pair("six", 6));
	c.insert(make_pair("seven", 7));
	c.insert(make_pair("eight", 8));
	c["nine"] = 9;
	cout << "请输入查找的数字：";
	int n;
	cin >> n;
	cin.get();
	map<string, int>::iterator pos;
	for (pos = c.begin(); pos != c.end(); pos++)
	{
		//cout << pos->second << ' ' << pos->first <<endl;
		if (pos->second == n)
		{
			cout << pos->first;
		}
	}
	if (pos == c.end())
	{
		cout << "输入错误";
	}
	c.clear();

	return 0;
}