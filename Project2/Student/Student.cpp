
#include"Student.h"


void Student::display()
{
	std::cout << "������" << name << ' ' << "�༶��" << classroom << "��" << ' ' << "ѧ�ţ�" << code << ' ' << "C++�ɼ���" << grade << endl;
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




