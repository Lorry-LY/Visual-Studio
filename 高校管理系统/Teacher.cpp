
#include "Teacher.h"
#include <vector>

using std::vector;

extern vector<string> vec_tittle;
extern vector<string> vec_department;

Teacher::Teacher()
{
	index_in_vec_department = index_in_vec_tittle = 0;
}
Teacher::Teacher(string name, bool sex, int age, Number number, int idx_tittle, int idx_department) :
	People(name, sex, age, number)
{
	index_in_vec_department = idx_department;
	index_in_vec_tittle = idx_tittle;
}
string Teacher::get_str_department()
{
	return vec_department[index_in_vec_department];
}
string Teacher::get_str_tittle()
{
	return vec_tittle[index_in_vec_tittle];
}