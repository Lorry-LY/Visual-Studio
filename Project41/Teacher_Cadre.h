#pragma once
#include "Teacher.h"
#include"Cadre.h"
class Teacher_Cadre :
	public Teacher, public Cadre
{
public:
	Teacher_Cadre(string name, int age, enum Teacher::sex s, string address, string phone, string title, string post, double wages) :Teacher(name, age, s, address, phone, title), Cadre(name, age, (Cadre::sex)s, address, phone, post), wages(wages) {};

	void show();

private:
	double wages;
};

