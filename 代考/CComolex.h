//CComplex.hpp

#pragma once
class CComplex
{
public:
	CComplex(double r = 0, double i = 0);
private:
	double real;
	double image;
public:
	void Display();
public:
	CComplex operator++(int);
	CComplex& operator++();
	friend CComplex operator+(CComplex c1, CComplex c2);
};
