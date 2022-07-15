#pragma once
#include "People.h"
#include <vector>

using std::vector;

class Reasecher :
	public People
{
private:
	string post;//职务
	int index_in_vec_lab;//该值表示string型vector：vec_lab中的某个元素的下标
public:
	Reasecher();
	Reasecher(string name, bool sex, int age, Number number, string post, int index_in_vec_lab);
	string get_post() { return post; }
	int get_lab_index() { return index_in_vec_lab; }
	string get_str_lab();
	void ser_lab(int index) { index_in_vec_lab = index; }
	void set_post(string new_post) { post = new_post; }
};



