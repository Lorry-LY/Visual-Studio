#pragma once
#include "People.h"

class Official :
	public People
{
private:
	int index_in_vec_politiclook;
	int index_in_vec_duty;

public:
	Official();
	Official(string name, bool sex, int age, Number number, int idx_in_vec_politiclook, int idx_in_vec_duty);
	int get_idx_politiclook() { return index_in_vec_duty; }
	int get_idx_duty() { return index_in_vec_duty; }
	string get_str_politiclook();
	string get_str_duty();
	void set_poloticlook(int index_politiclook) { index_in_vec_politiclook = index_politiclook; }
	void ser_duty(int index_duty) { index_in_vec_duty = index_duty; }

};
