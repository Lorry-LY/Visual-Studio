#include "Park.h"

Park::Park(int allNumber)
{
	this->allNumber = allNumber;
	this->aviNumber = allNumber;
	this->income = 0;
	for (int i = 0; i < allNumber; i++)
	{
		car[i] = "";
	}
}

string Park::getCar(int i)
{
	return car[i];
}

int Park::getAllNumber()
{
	return allNumber;
}

int Park::getAviNumber()
{
	return aviNumber;
}

int Park::getIncome()
{
	return income;
}

void Park::setCar(string car, int i)
{
	this->car[i] = car;
}

void Park::setAllNumber(int allNumber)
{
	this->allNumber = allNumber;
}

void Park::setAviNumber(int aviNumber)
{
	this->aviNumber = aviNumber;
}

void Park::setIncome(int income)
{
	this->income = income;
}

void Park::showInfo()
{
	if (allNumber - aviNumber != 0)
	{
		cout << "停车场目前停放了" << allNumber - aviNumber << "辆汽车：";
		for (int i = 0; i < allNumber; i++)
		{
			if (car[i] != "")
			{
				cout << car[i] << ",";
			}
		}
	}
	else
	{
		cout << "停车场为空，";
	}
	cout << "共收入" << income << "元停车费" << endl;

}
