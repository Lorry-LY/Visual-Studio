//CFraction.cpp

#include "CFraction.h"

void CFraction::display()		//输出函数。
{
	cout << this->cfz << '/' << this->cfm << endl;
}

bool operator>(CFraction& cf1, CFraction& cf2)		//操作符>全局重载。用途：函数模板判断时用到。返回bool值用于判断
{
	float num1, num2;
	num1 = (float)cf1.cfz / cf1.cfm;
	num2 = (float)cf2.cfz / cf2.cfm;
	if (num1 > num2)
	{
		return true;
	}
	else return false;
}