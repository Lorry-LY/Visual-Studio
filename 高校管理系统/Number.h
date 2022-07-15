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
	//���ݴ�������ݹ���һ��number
	//Ŀ��������һ����ʽ�ǣ���+��+��+�Ա�0/1��+��λ��num��
	//���磺Number(2020,12,25,0,5555) = "2020122505555"
	string get_number() const { return number; }

	void set_number(string new_number) { number = new_number; }
	void show_number();//δʵ��

	Number operator = (const Number& id);
	Number operator = (const char* ch);//��ͨ�����ַ�����ֵ
	Number operator = (const string str);//��ͨ��string��ֵ
	//Number operator << (const Number& id);
};

bool change_number(Number& a_number, int new_num);//�޸�һ��number�������λΪnew_num;