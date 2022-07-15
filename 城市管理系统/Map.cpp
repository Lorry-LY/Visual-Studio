//Map.cpp

#include "Map.h"
#include<math.h>
#include<fstream>
Map::Map(int maxc)
{
	data = new City[maxc];
	maxCounter = maxc;
	curCounter = 0;
}

Map::~Map()
{
	delete[] data;
}

Map::Map(Map& m)
{
	this->data = m.data;
	this->curCounter = m.curCounter;
	this->maxCounter = m.maxCounter;
}

double Map::Distance(int x1, int y1, int x2, int y2)
{
	return sqrt((double)(x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2));
}

void Map::AddCity(int num, string na, int x, int y)
{
	if (this->curCounter == this->maxCounter)
	{
		cout << "链表已满。" << endl;
	}
	else
	{
		int error = 0;
		for (int i = 0; i < curCounter; i++)
		{
			if (data[i].number == num)
			{
				cout << "城市编号重复。" << endl;
				error++;
				break;
			}
		}
		if (!error)
		{
			City item(num, na, x, y);
			this->data[this->curCounter] = item;
			this->curCounter++;
		}
	}
}

void Map::DeleteCity(int i)
{
	if (!curCounter)
	{
		cout << "链表为空。" << endl;
	}
	else if (i<0 || i>curCounter - 1)
	{
		cout << "编号超出链表范围。" << endl;
	}
	else
	{
		for (i++; i < curCounter; i++)
		{
			data[i - 1] = data[i];
		}
		curCounter--;
	}
}

void Map::UpdateCity(int i, int num, string na, int x, int y)
{
	if (i<0 || i>curCounter - 1)
	{
		cout << "下标超出链表范围。" << endl;
	}
	City item(num, na, x, y);
	data[i] = item;
}

int Map::FindCity(int num)
{
	for (int i = 0; i < curCounter; i++)
	{
		if (data[i].getNum() == num)
		{
			return i;
		}
	}
	return -1;
}

void Map::ShowCities()
{
	for (int i = 0; i < curCounter; i++)
	{
		data[i].show();
	}
}

void Map::ShowCity(int i)
{
	data[i].show();
}

int Map::GetCurCounter()
{
	return this->curCounter;
}

int Map::GetPositionX(int i)
{
	return data[i].x;
}

int Map::GetPositionY(int i)
{
	return data[i].y;
}

void Map::ImportDataBase()
{
	string str = "database.txt";
	ReadCity(str);
}

void Map::ReadCity(string filename)
{
	ifstream file(filename);
	int i;
	file >> i;
	while (!file.eof())
	{
		int number;
		string name;
		int x, y;
		file >> number >> name >> x >> y;
		if (!name.empty())
		{
			AddCity(number, name, x, y);
		}
	}
	file.close();
}

void Map::SavaCity(string filename)
{
	ofstream file(filename, ios::trunc);
	file << this->curCounter << endl;
	for (int i = 0; i < curCounter; i++)
	{
		file << data[i].number << ' ' << data[i].name << ' ' << data[i].x << ' ' << data[i].y << endl;
	}
	file.close();
}