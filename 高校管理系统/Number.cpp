#include "Number.h"
#include "tool.h"

Number::Number()
{
	number = "0000000000000";
}
Number::Number(const string str)
{
	number = str;
}
Number::Number(int year, int month, int day, bool sex, int num)
{
	char temp[10];
	char reasult[25] = "\0";
	sprintf_s(temp, "%d", year);
	strcat_s(reasult, temp);
	if (month < 10)
	{
		strcat_s(reasult, "0");
	}
	sprintf_s(temp, "%d", month);
	strcat_s(reasult, temp);
	if (day < 10)
	{
		strcat_s(reasult, "0");
	}
	sprintf_s(temp, "%d", day);
	strcat_s(reasult, temp);
	sprintf_s(temp, "%d", sex);
	strcat_s(reasult, temp);
	if (num < 10)
	{
		strcat_s(reasult, "000");
	}
	else if (num < 100)
	{
		strcat_s(reasult, "00");
	}
	else if (num < 1000)
	{
		strcat_s(reasult, "0");
	}
	sprintf_s(temp, "%d", num);
	strcat_s(reasult, temp);

	number = reasult;
}
void Number::show_number()
{
	//待实现
}
Number Number::operator=(const Number& id)
{
	number = id.get_number();
	return *this;
}
Number Number::operator=(const char* ch)
{
	number = ch;
	return *this;
}
Number Number::operator=(const string str)
{
	number = str;
	return *this;
}


bool change_number(Number& a_number, int new_num)
{
	string strtemp = a_number.get_number();//这个变量用来存储新输入的编号
	strtemp.pop_back();
	strtemp.pop_back();
	strtemp.pop_back();
	strtemp.pop_back();
	char temp1[4];
	char temp2[25];

	for (int i = 0; i < strtemp.size(); i++)
	{
		temp2[i] = strtemp[i];
	}
	temp2[strtemp.size() - 1] = '\0';

	sprintf_s(temp1, "%d", new_num);
	if (new_num < 10)
	{
		strcat_s(temp2, "000");
	}
	else if (new_num < 100)
	{
		strcat_s(temp2, "00");
	}
	else if (new_num < 1000)
	{
		strcat_s(temp2, "0");
	}
	strcat_s(temp2, temp1);

	strtemp = temp2;

	bool flag = 0;

	extern vector<string> vec_number;//提示编译器在其他文件中寻找定义，不然编译报错

	while (1)
	{
		if (find(vec_number, strtemp) != -1)
		{
			//显示重名，重新输入new——num，
		}
		else
		{
			flag = 1;
		}

		if (flag) break;
	}

	//程序到此意为这这个新的num可以使用
	a_number.set_number(strtemp);

	return 1;
}