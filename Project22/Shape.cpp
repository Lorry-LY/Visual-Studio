//Shape.cpp

#include "shape.h"
Shape* Shape::findAndClone(int nShapeType)
{
	switch (nShapeType)
	{
	case 0:
	{
		return new Triangle;
	}
	case 1:
	{
		return new Rectange;
	}
	case 2:
	{
		return new Square;
	}
	case 3:
	{
		return new Circle;
	}
	case 4:
	{
		return new Elipse;
	}
	default:
	{
		cout << "wrong typenumber" << endl;
		return nullptr;
	}
	}
}

double Triangle::Area(void) const
{
	double p = (a + b + c) / 2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
double Triangle::Perimeter(void) const
{
	return a + b + c;
}
istream& Triangle::read(istream& is)
{
	is >> a >> b >> c;
	return is;
}
ostream& Triangle::write(ostream& os)const
{
	ofstream out("d:/textbook.txt", ios::out | ios::app);//打开文件，以cout的形式追加到app后面
	os << "Triangle:" << a << ' ' << b << ' ' << c <<' ';
	out << "Triangle" << a << ' ' << b << ' ' << c << endl;
	return os;
}

double Rectange::Area(void) const
{
	return a * b;
}
double Rectange::Perimeter(void) const
{
	return 2 * (a + b);
}
istream& Rectange::read(istream& is)
{
	is >> a >> b;
	return is;
}
ostream& Rectange::write(ostream& os)const
{
	ofstream out("d:/textbook.txt", ios::out | ios::app);//打开文件，以cout的形式追加到app后面
	os << "Rectange:" << a << ' ' << b << ' ';
	out << "Rectange" << a << ' ' << b << endl;
	return os;
}

double Elipse::Area(void) const
{
	return PI * a * b;
}
double Elipse::Perimeter(void) const
{
	return 2 * PI * b + 4 * (a - b);
}
istream& Elipse::read(istream& is)
{
	is >> a >> b;
	return is;
}
ostream& Elipse::write(ostream& os)const
{
	ofstream out("d:/textbook.txt", ios::out | ios::app);//打开文件，以cout的形式追加到app后面
	os << "Elipse:" << a << ' ' << b << ' ' ;
	out << "Elipse" << a << ' ' << b << endl;
	return os;
}

double Square::Area(void) const
{
	return pow(a, 2);
}
double Square::Perimeter(void) const
{
	return 4 * a;
}
istream& Square::read(istream& is)
{
	is >> a;
	return is;
}
ostream& Square::write(ostream& os)const
{
	ofstream out("d:/textbook.txt", ios::out | ios::app);//打开文件，以cout的形式追加到app后面
	os << "Square:" << a << ' ' ;
	out << "Square" << a << endl;
	return os;
}

double Circle::Area(void) const
{
	return PI * pow(r, 2);
}
double Circle::Perimeter(void) const
{
	return PI * 2 * r;
}
istream& Circle::read(istream& is)
{
	is >> r;
	return is;
}
ostream& Circle::write(ostream& os)const
{
	ofstream out("d:/textbook.txt", ios::out | ios::app);//打开文件，以cout的形式追加到app后面
	os << "Circle:" << r << ' ';
	out << "Circle" << r << endl;
	return os;
}