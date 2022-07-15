#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque<int>d1;
	//为d1添加五个元素0-5；
	for (int i = 0; i < 5; i++)
	{
		d1.push_back(i);
	}
	//在d1前面添加五个元素；
	for (int i = 5; i > 0; i--)
	{
		d1.push_front(i * 10);
	}
	//输出此时d1的长度
	cout <<"容器的长度为："<< d1.size() << endl;
	//顺序输出容器内个元素的值
	deque<int>::iterator de;
	for (de = d1.begin(); d1.end() != de; de++)
	{
		cout << *de << ' ';
	}
	cout << endl;
	//修改d1头部尾部元素的值
	d1.front() = 100;
	d1.back() = 10;
	cout << d1.front() << ' ' << d1.back() <<endl;
	//删除d1第3-5号元素
	d1.erase(d1.begin() + 2, d1.begin() + 5);
	//输出此时d1的长度
	cout << "容器的长度为：" << d1.size() << endl;
	//顺序输出容器内个元素的值
	for (de = d1.begin(); d1.end() != de; de++)
	{
		cout << *de << ' ';
	}
	cout << endl;
	//在d1第三个元素插入元素；
	d1.insert(d1.begin() + 2, -50);
	//在d1第三个元素到第五个元素插入8；
	d1.insert(d1.begin() + 2, 3, 8);
	//在d1后面插入一个新的d1；
	d1.insert(d1.end(), d1.begin(), d1.end());
	//输出此时d1的长度
	cout << "容器的长度为：" << d1.size() << endl;
	//顺序输出容器内个元素的值
	for (de = d1.begin(); d1.end() != de; de++)
	{
		cout << *de << ' ';
	}
	cout << endl;
	return 0;
}