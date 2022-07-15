#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque<int>d1;
	//Ϊd1������Ԫ��0-5��
	for (int i = 0; i < 5; i++)
	{
		d1.push_back(i);
	}
	//��d1ǰ��������Ԫ�أ�
	for (int i = 5; i > 0; i--)
	{
		d1.push_front(i * 10);
	}
	//�����ʱd1�ĳ���
	cout <<"�����ĳ���Ϊ��"<< d1.size() << endl;
	//˳����������ڸ�Ԫ�ص�ֵ
	deque<int>::iterator de;
	for (de = d1.begin(); d1.end() != de; de++)
	{
		cout << *de << ' ';
	}
	cout << endl;
	//�޸�d1ͷ��β��Ԫ�ص�ֵ
	d1.front() = 100;
	d1.back() = 10;
	cout << d1.front() << ' ' << d1.back() <<endl;
	//ɾ��d1��3-5��Ԫ��
	d1.erase(d1.begin() + 2, d1.begin() + 5);
	//�����ʱd1�ĳ���
	cout << "�����ĳ���Ϊ��" << d1.size() << endl;
	//˳����������ڸ�Ԫ�ص�ֵ
	for (de = d1.begin(); d1.end() != de; de++)
	{
		cout << *de << ' ';
	}
	cout << endl;
	//��d1������Ԫ�ز���Ԫ�أ�
	d1.insert(d1.begin() + 2, -50);
	//��d1������Ԫ�ص������Ԫ�ز���8��
	d1.insert(d1.begin() + 2, 3, 8);
	//��d1�������һ���µ�d1��
	d1.insert(d1.end(), d1.begin(), d1.end());
	//�����ʱd1�ĳ���
	cout << "�����ĳ���Ϊ��" << d1.size() << endl;
	//˳����������ڸ�Ԫ�ص�ֵ
	for (de = d1.begin(); d1.end() != de; de++)
	{
		cout << *de << ' ';
	}
	cout << endl;
	return 0;
}