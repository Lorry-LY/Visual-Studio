
//duty.h

#ifndef DUTY_H
#define DUTY_H


#include "Student.h"
class duty :
	public Student
{
private:
	string thing;
public:
	duty(string name, int classroom, string code, int grade, string thing) :Student(name,classroom,code,grade),thing(thing)  {};
	duty(Student& stu, string thing) :Student(stu), thing(thing) {};
	void display();
};

#endif // !DUTY_H

