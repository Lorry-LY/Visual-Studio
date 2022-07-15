#pragma once
#include "Tea_Off.h"
Tea_Off::Tea_Off() :Teacher::Teacher(), Official::Official()
{
}
Tea_Off::Tea_Off(string name, bool sex, int age, Number number, int idx_tittle, int idx_department, int idx_in_vec_politiclook, int idx_in_vec_duty) :
	Teacher::Teacher(name, sex, age, number, idx_tittle, idx_department),
	Official::Official(name, sex, age, number, idx_tittle, idx_department)
{
}