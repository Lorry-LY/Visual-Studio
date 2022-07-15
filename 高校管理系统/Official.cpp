#include "Official.h"
#include <vector>

using std::vector;

extern vector<string> vec_duty;
extern vector<string> vec_politiclook;

Official::Official() :People::People()
{
	index_in_vec_duty = index_in_vec_politiclook = 0;
}
Official::Official(string name, bool sex, int age, Number number, int idx_politiclook, int idx_duty) :
	People::People(name, sex, age, number)
{
	index_in_vec_duty = idx_duty;
	index_in_vec_politiclook = idx_politiclook;
}
string Official::get_str_duty()
{
	return vec_duty[index_in_vec_duty];
}
string Official::get_str_politiclook()
{
	return vec_politiclook[index_in_vec_politiclook];
}