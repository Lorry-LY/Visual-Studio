
//T2.cpp
#include<iostream>
#include<fstream>
#include"CComolex.h"
using namespace std;

int main()
{
	CComplex c1(6.6, 7.7);
	CComplex c2(8.3, 9.2);
	CComplex c3, c4, c5;
	c3 = c1++;
	c4 = ++c2;
	c5 = c3 + c4;
	c1.Display();
	c2.Display();
	c3.Display();
	c4.Display();
	c5.Display();
	return 0;
}