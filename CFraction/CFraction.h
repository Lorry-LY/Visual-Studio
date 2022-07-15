//CFraction.h

#pragma once
#include<iostream>
using namespace std;
class CFraction
{
public:			//申明成员变量，public原因：因为外部对操作符>全局重载时用到。
	int cfz;	
	int cfm;
public:
	CFraction()		//无参构造函数，用途：函数模板声明第三者时候用到。
	{
		this->cfm = 1;
		this->cfz = 1;
	}
	CFraction(int cfz, int cfm) :cfz(cfz), cfm(cfm) {};		//构造函数，用途：创建对象；
	CFraction& operator=(CFraction& cf)			//操作符=内部重载	用途：函数模板赋值时用到。
	{
		this->cfz = cf.cfz;
		this->cfm = cf.cfm;
		return *this;
	}
	void display();		//输出函数。
};
bool operator>(CFraction& cf1, CFraction& cf2);






