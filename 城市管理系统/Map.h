//Map.h
#ifndef MAP_H
#define MAP_H

#include<iostream>
#include"City.h"
#include<list>
using namespace std;

class Map
{
private:
	City* data;
	int curCounter;
	int maxCounter;
	
public:
	Map(int maxc = 10);
	~Map();
	void ImportDataBase();
	Map(Map& m);
	double Distance(int x1, int y1, int x2, int y2);
	void AddCity(int num, string na, int x, int y);
	void DeleteCity(int num);
	void SavaCity(string filename);
	void ReadCity(string filename);
	void UpdateCity(int i, int num, string na, int x, int y);
	int FindCity(int num);
	void ShowCities();
	int GetCurCounter();
	int GetPositionX(int i);
	int GetPositionY(int i);
	void ShowCity(int i);


};

#endif // !MAP_H

