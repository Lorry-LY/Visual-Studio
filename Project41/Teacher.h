#pragma once
#include<iostream>
#include<string>
using namespace std;

class Teacher
{
public:
	enum sex { male, female }sexy;
	Teacher(string name, int age, enum Teacher::sex s, string address, string phone, string title) :name(name), age(age), address(address), phone(phone), title(title) { this->sexy = s; };

	void display();

protected:
	string name;
	string address;
	int age;
	string phone;

	string title;

};

