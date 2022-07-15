#include<iostream>
#include<string>
//#include"CCircle.h"
//#include"CRectangle.h"
//完成选做部分时打开
#include"CRundrect.h"
using namespace std;
void fn(CShape& c);
int main()
{
	CCircle circle(10.0, 6.7, 8.7);
	CRectangle rect(200.0, 15.0, 9.7, 10.7);
	fn(circle);
	fn(rect);
	//完成选做部分时打开
	CRundrect rundrect(200.0, 15.0, 10.0, 9.7, 10.7);
	//fn(rundrect);
}
void fn(CShape& shape)
{
	cout << "定位坐标：" << shape.GetX() << "," << shape.GetY() << endl;
	cout << "面积：" << shape.Area() << endl;
}