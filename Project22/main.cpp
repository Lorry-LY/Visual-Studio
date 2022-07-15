//main.cpp

#include <iostream>
#include <list>
#include <fstream>//对文件进行操作
#include "Shape.h"
using namespace std;

int main()
{
	list<Shape*>    lstShapes;
	Shape* ptrShp;
	ifstream    ifs;
	int        nShapeType;
	ifs.open("d:/test.txt");

	while (!ifs.eof())
	{
		ifs >> nShapeType;
		ptrShp = Shape::findAndClone(nShapeType);
		if (ptrShp)
		{
			ptrShp->read(ifs);
			lstShapes.push_back(ptrShp);
		}
	}

	for (auto shp : lstShapes)
	{
		shp->write(cout) << ", ";
		cout << shp->Area() << ", ";
		cout << shp->Perimeter() << ", ";
		cout << endl;
	}

	for (auto shp : lstShapes)
	{
		delete shp;
	}
	return 0;
}