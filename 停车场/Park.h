#pragma once

#include<iostream>

using namespace std;

class Park
{
private:
	int allNumber;
	int aviNumber;
	int income;
	string car[100];

public:
	Park(int allNumber);

	string getCar(int i);
	int getAllNumber();
	int getAviNumber();
	int getIncome();
	void setCar(string car, int i);
	void setAllNumber(int allNumber);
	void setAviNumber(int aviNumber);
	void setIncome(int Income);

	void showInfo();


};

