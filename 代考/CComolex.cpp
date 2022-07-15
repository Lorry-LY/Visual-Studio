//CComplex.cpp

#include "CComolex.h"
#include<iostream>
using namespace std;
CComplex::CComplex(double r, double i)
	:real(r), image(i)
{

}
void CComplex::Display()
{
	cout << real << "+i" << image << endl;
}
CComplex CComplex::operator++(int)//��׺++
{
	CComplex tmp = *this;
	real += 1;
	image++;
	return tmp;

}
CComplex& CComplex::operator++()
{
	//�ڴ���ӳ���
	this->real++;
	this->image++;
	return *this;
}
CComplex operator+(CComplex c1, CComplex c2)
{
	//�ڴ���ӳ���
	c1.real = c1.real + c2.real;
	c1.image = c1.image + c2.image;
	return c1;

}