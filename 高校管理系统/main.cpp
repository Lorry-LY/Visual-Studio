#include "tool.h"
#include "People.h"
#include "Number.h"
#include "Reascher.h"
#include "Teacher.h"
#include "Official.h"
#include "Tea_Off.h"
#include "choice.h"


//�о����н����õ�����ʱ����
int int_1, int_2, int_3;

string str_1, str_2, str_3;

vector<string> vec_str_1, vec_str_2, vec_str_3;
vector<int> vec_int_1, vec_int_2, vec_int_3;

vector<const char*> vec_words;//���ڴ���ַ�����ֵ������

//�����б�
vector<Reasecher> vec_obj_reasecher;
vector<Teacher> vec_obj_teacher;
vector<Official> vec_obj_official;
vector<Tea_Off> vec_obj_tea_off;

vector<string> vec_number;//�洢����ʹ���е�number��
vector<string> vec_name;//�洢����name

//�����б�
vector<string> vec_lab;//�о���Ա���е�ʵ�����б�
vector<string> vec_department;//��ʦ���е�Ժϵ�б�
vector<string> vec_tittle;//��ʦ���ְ���б�
vector<string> vec_duty;//������Ա���ְ���б�
vector<string> vec_politiclook;//������ò�б�

int main(void)
{

	creat_all();

	choice0();

	information_save();

	system("pause");

	return 0;
}