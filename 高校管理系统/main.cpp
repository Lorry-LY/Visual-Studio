#include "tool.h"
#include "People.h"
#include "Number.h"
#include "Reascher.h"
#include "Teacher.h"
#include "Official.h"
#include "Tea_Off.h"
#include "choice.h"


//列举所有将会用到的临时变量
int int_1, int_2, int_3;

string str_1, str_2, str_3;

vector<string> vec_str_1, vec_str_2, vec_str_3;
vector<int> vec_int_1, vec_int_2, vec_int_3;

vector<const char*> vec_words;//用于存放字符串常值的容器

//对象列表
vector<Reasecher> vec_obj_reasecher;
vector<Teacher> vec_obj_teacher;
vector<Official> vec_obj_official;
vector<Tea_Off> vec_obj_tea_off;

vector<string> vec_number;//存储所有使用中的number库
vector<string> vec_name;//存储所有name

//特性列表
vector<string> vec_lab;//研究人员类中的实验室列表
vector<string> vec_department;//教师类中的院系列表
vector<string> vec_tittle;//教师类的职称列表
vector<string> vec_duty;//行政人员类的职务列表
vector<string> vec_politiclook;//政治面貌列表

int main(void)
{

	creat_all();

	choice0();

	information_save();

	system("pause");

	return 0;
}