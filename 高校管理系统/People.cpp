#include "People.h"

void People::set_number(Number new_num)
{
	id = new_num;
}
People::People()
{
	name = "未知人员";
	sex = 0;
	age = 0;
	id = "未知id";
}
People::People(string na, bool se, int ag, Number nu)
{
	name = na;
	sex = se;
	age = ag;
	id = nu;
}