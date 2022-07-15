#include "Reascher.h"

Reasecher::Reasecher() :People::People()
{
	post = "Î´ÖªÖ°Îñ";
	index_in_vec_lab = 0;
}
Reasecher::Reasecher(string name, bool sex, int age, Number number, string po, int index) :
	People(name, sex, age, number)
{
	post = po;
	index_in_vec_lab = index;
}

extern vector<string> vec_lab;
string Reasecher::get_str_lab()
{
	return vec_lab[index_in_vec_lab];
}