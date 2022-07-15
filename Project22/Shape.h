//Shape.h

#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include <math.h>
using namespace std;
const double PI = 3.14;

class Shape
{
public:
	static Shape* findAndClone(int);
	virtual double Area(void) const = 0;
	virtual double Perimeter(void) const = 0;
	virtual istream& read(istream& is) = 0;
	virtual ostream& write(ostream& os)const = 0;
	
};

class Triangle :public Shape
{
public:
	virtual double Area(void) const;
	virtual double Perimeter(void) const;
	virtual istream& read(istream& is);
	virtual ostream& write(ostream& os)const;
	
private:
	double a, b, c;
};

class Rectange :public Shape
{
public:
	virtual double Area(void) const;
	virtual double Perimeter(void) const;
	virtual istream& read(istream& is);
	virtual ostream& write(ostream& os)const;
private:
	double a, b;
};

class Elipse :public Shape
{
public:
	virtual double Area(void) const;
	virtual double Perimeter(void) const;
	virtual istream& read(istream& is);
	virtual ostream& write(ostream& os)const;
	void getab()
	{
		if (a < b)
		{
			a = a + b;
			b = a - b;
			a = (a - b) / 2;
		}
		return;
	}
private:
	double a, b;
};

class Square :public Rectange
{
public:
	virtual double Area(void) const;
	virtual double Perimeter(void) const;
	virtual istream& read(istream& is);
	virtual ostream& write(ostream& os)const;
private:
	double a;
};

class Circle :public Elipse
{
public:
	virtual double Area(void) const;
	virtual double Perimeter(void) const;
	virtual istream& read(istream& is);
	virtual ostream& write(ostream& os)const;
private:
	double r;
};