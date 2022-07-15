#pragma once

#include<iostream>
using namespace std;

class Cadre
{
public:
	enum sex { male, female }sexy;
	Cadre(string name, int age, enum Cadre::sex s, string address, string phone, string post) :name(name), age(age), address(address), phone(phone), post(post) { this->sexy = s; };
	void display();

protected:
	string name;
	string address;
	int age;
	
	string phone;

	string post;
};

