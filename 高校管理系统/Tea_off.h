#pragma once
#include "People.h"
#include "Teacher.h"
#include "Official.h"
class Tea_Off :
	public Teacher, public Official
{
private:

public:
	Tea_Off();
	Tea_Off(string name, bool sex, int age, Number number, int idx_tittle, int idx_department, int idx_in_vec_politiclook, int idx_in_vec_duty);


};
