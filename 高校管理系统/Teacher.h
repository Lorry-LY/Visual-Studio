#pragma once
#include "People.h"

class Teacher :
	public People
{
private:
	int index_in_vec_tittle;
	int index_in_vec_department;
public:
	Teacher();
	Teacher(string name, bool sex, int age, Number number, int idx_tittle, int idx_department);
	int get_idx_tittle() { return index_in_vec_tittle; }
	int get_idx_department() { return index_in_vec_department; }
	string get_str_tittle();
	string get_str_department();
	void set_tittle(int idx_tittle) { index_in_vec_tittle = idx_tittle; }
	void set_department(int idx_department) { index_in_vec_department = idx_department; }



};