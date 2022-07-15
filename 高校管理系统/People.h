#pragma once
#include <string>
#include "Number.h"

using std::string;

class People
{
private:
	string name;
	bool sex;
	int age;
	Number id;
public:
	People();
	People(string name, bool sex, int age, Number number);

	string get_name() { return name; }
	bool get_sex() { return sex; }
	int get_age() { return age; }
	Number get_id() { return id; }

	void set_name(string newname) { name = newname; }
	void change_sex() { sex = !sex; }
	void sex_age(int newage) { age = newage; }
	void set_number(Number new_number);
	virtual void show_infor() { ; }//Œ¥ µœ÷
};


