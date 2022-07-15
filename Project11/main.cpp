#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	list<int>list1;		//定义空链表
	list<int>::iterator it;		//定义迭代器

	//插入5个元素1-5；
	int i = 1;
	for (it = list1.begin();i<=5; i++)
	{
		list1.push_back(i);
	}
	//输出链表
	for (it = list1.begin(); it != list1.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	//链表头部插入元素
	list1.push_front(5);
	//逆向遍历链表
	for (it = list1.end(), it--; it != list1.begin(); it--)
	{
		cout << *it << ' ';
	}
	cout << endl;


	//删除最后一个元素
	list1.erase(list1.begin());
	//输出链表
	for (it = list1.begin(); it != list1.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	//查找元素
	int search = 4;
	list<int>::iterator pos = find(list1.begin(), list1.end(), search);
	if (pos != list1.end())
	{
		cout << "元素位置为：" << distance(list1.begin(), pos) <<endl;
	}
	else
	{
		cout << "未找到对应元素。" << endl;
	}

	//排序链表
	list1.sort();
	//输出链表
	for (it = list1.begin(); it != list1.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	HashSet h
	//输出链表
	for (it = list1.begin(); it != list1.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	//清除链表
	list1.clear();

	return 0;
}