#include<iostream>
#include<string>
//#include"CCircle.h"
//#include"CRectangle.h"
//���ѡ������ʱ��
#include"CRundrect.h"
using namespace std;
void fn(CShape& c);
int main()
{
	CCircle circle(10.0, 6.7, 8.7);
	CRectangle rect(200.0, 15.0, 9.7, 10.7);
	fn(circle);
	fn(rect);
	//���ѡ������ʱ��
	CRundrect rundrect(200.0, 15.0, 10.0, 9.7, 10.7);
	//fn(rundrect);
}
void fn(CShape& shape)
{
	cout << "��λ���꣺" << shape.GetX() << "," << shape.GetY() << endl;
	cout << "�����" << shape.Area() << endl;
}