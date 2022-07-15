#pragma once
#include <string>

using std::string;
using std::to_string;
using std::stoll;

class Number
{
private:
	string number;
public:
	Number();
	Number(const string str);
	Number(int year, int month, int day, bool sex, int num);
	//根据传入的数据构造一个number
	//目的是生成一个格式是：年+月+日+性别（0/1）+四位数num，
	//例如：Number(2020,12,25,0,5555) = "2020122505555"
	string get_number() const { return number; }

	void set_number(string new_number) { number = new_number; }
	void show_number();//未实现

	Number operator = (const Number& id);
	Number operator = (const char* ch);//能通过常字符串赋值
	Number operator = (const string str);//能通过string赋值
	//Number operator << (const Number& id);
};

bool change_number(Number& a_number, int new_num);//修改一个number的最后四位为new_num;