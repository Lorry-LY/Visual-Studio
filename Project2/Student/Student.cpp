
#include"Student.h"


void Student::display()
{
	std::cout << "姓名：" << name << ' ' << "班级：" << classroom << "班" << ' ' << "学号：" << code << ' ' << "C++成绩：" << grade << endl;
}

void Student::modifycode(string code)
{
	this->code = code;
}

void Student::modifygrade(unsigned grade)
{
	this->grade = grade;
}

void Student::modifyName(string name)
{
	this->name = name;
}




