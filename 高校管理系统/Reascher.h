#pragma once
#include "People.h"
#include <vector>

using std::vector;

class Reasecher :
	public People
{
private:
	string post;//ְ��
	int index_in_vec_lab;//��ֵ��ʾstring��vector��vec_lab�е�ĳ��Ԫ�ص��±�
public:
	Reasecher();
	Reasecher(string name, bool sex, int age, Number number, string post, int index_in_vec_lab);
	string get_post() { return post; }
	int get_lab_index() { return index_in_vec_lab; }
	string get_str_lab();
	void ser_lab(int index) { index_in_vec_lab = index; }
	void set_post(string new_post) { post = new_post; }
};



