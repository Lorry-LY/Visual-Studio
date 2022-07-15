#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	list<int>list1;		//���������
	list<int>::iterator it;		//���������

	//����5��Ԫ��1-5��
	int i = 1;
	for (it = list1.begin();i<=5; i++)
	{
		list1.push_back(i);
	}
	//�������
	for (it = list1.begin(); it != list1.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	//����ͷ������Ԫ��
	list1.push_front(5);
	//�����������
	for (it = list1.end(), it--; it != list1.begin(); it--)
	{
		cout << *it << ' ';
	}
	cout << endl;


	//ɾ�����һ��Ԫ��
	list1.erase(list1.begin());
	//�������
	for (it = list1.begin(); it != list1.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	//����Ԫ��
	int search = 4;
	list<int>::iterator pos = find(list1.begin(), list1.end(), search);
	if (pos != list1.end())
	{
		cout << "Ԫ��λ��Ϊ��" << distance(list1.begin(), pos) <<endl;
	}
	else
	{
		cout << "δ�ҵ���ӦԪ�ء�" << endl;
	}

	//��������
	list1.sort();
	//�������
	for (it = list1.begin(); it != list1.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	HashSet h
	//�������
	for (it = list1.begin(); it != list1.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	//�������
	list1.clear();

	return 0;
}