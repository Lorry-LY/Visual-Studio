

#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
	string name;
	unsigned int classroom;
	string code;
	unsigned int grade;
public:
	Student(string name, unsigned classroom, string code, unsigned grade) :name(name), classroom(classroom), code(code), grade(grade) {};
	void display();
	void modifygrade(unsigned grade);
	void modifyName(string name);
	void modifycode(string code);

};


