#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ofstream;

/*
	toolϵ���ļ��ṩ����ϵͳʵ�ֵĸ��ֹ��ܣ�
	��ͷ�ļ�����������������

	1.	�����������[min��max]��ֵ�����磺
	read_in(20,30,"����ֵ"��������ʾ:����������ֵ:
	read_in(2000,9999��"����")������ʾ:����������:

	*����������Ҫ����߰�����ĸ,��Ҫ���ظ�����ֱ������.

	2.����һ���ַ��������Զ��Թ��ո񣬺����ҷ�����.....
	https://www.cnblogs.com/ECJTUACM-873284962/p/11619496.html
	���Բ�û������

	2.  �������vector<const char*>����һ���洢����Ҫ�г���ѡ�
	vector�и���Ԫ��Ϊ�ַ�����ֵ����ѡ��
	Ч��������Ļ��������ʾѡ�������һ�����ڸ���ѡ��֮���������
	���繲��5��ѡ��򷵻�ֵΪ[1,5]֮���һ������
	����Ҫʵ��һ��ֻ������ѡ��Ĳ˵�:

	vec_words.clear();
	vec_words.push_back("�����Ҫ������");
	vec_words.push_back("��ʳ�����ʿû�ô�");

	reasult = output_list(vec_words);

	��Ļ�Ͻ���ʾ��

	1.�����Ҫ������
	2.��ʳ�����ʿû�ô�
	���������ѡ�

	�����������˵��reasultֻ����1��2,

	*��ÿ��ʹ��ǰ����Ҫ��ǰ��ѡ������vector
	*ʹ����ɺ󽫻��Զ����vector

	3.��һ���洢string��vector������һ��string������Ŀ�������е��±ꣻ
	���û���ҵ��򷵻�-1��

	��Ϊ����string��vector���±�Ϊ0�Ķ�������ΪĬ�ϵ�ʵ��������ʵ�ʵ�ʵ����
	����ʵ�����б�רҵ�б�ְ�ƣ���ʦ���е�tittle�������о���Ա���е�post���б�������Ա��duty�б�
	��Щ�б�����ͬ��vector<string>)�ĵ�һ��Ԫ�ض�������Ϊ  "δ֪XX"
	�Դ�֮���ÿ��ֵ���Ƕ�Ӧ��ʵ����/רҵ/ְ��/duty.....

	4.��ʼ�������б������⣩����ÿ���б���׸�Ԫ����Ϊ"δ֪xxx"�ĸ�ʽ��
	ͬʱ��������趨֮��������������Щ�����ں����ڲ���˵����

	*���������г���֮��ֱ��ʹ��ͳ�ƹ��ܲ鿴��Щ��Ա

	5.����һ��string�͵�vector��������Ļ�������ʾ��A����������±�Ϊ1����β��ÿ��Ԫ�ذ�����������Ļ�ϣ�
	����������ʾ��B��ִ�н�����ش�һ��[1��vec.size()- 1 + 1]֮���ֵ�����ڹ���һЩ�˵���
	�ر�ģ�������BΪ"back"�������:vec.size().������һ��
	������BΪ�����ؼ����򽫰������Ĵ����ַ������;

	*���ڲ���

	6.7.�����ַ�ʽ����һ���ˣ��ҵ��ˣ��򷵻�1��ͬʱ��vec_int3[0]��vec_int3[1]�и��洢һ������
	ǰ�ߴ�����Ա���࣬1 = official��2 = teacher��3 = tea_off, 4 = reasecher
	���ߴ����ڶ�Ӧ�Ķ����б��е��±�

	8.�浵��Ĭ�ϱ�����D:\\system.txt��

	...
*/


int read_int(int min, int max, const char* key_words);
int output_list(vector<const char*>& vec_list);//���ô�ֵ��ȷ���ú����
int find(vector<string> a_vec_to_be_find, string str_you_want_find);
void creat_all(void);
int choose_list(vector<string> a_str_vec_to_create_list, const char* Akey_words, const char* Bkey_words);
bool find_people_in_number();
bool find_people_in_name();

void information_save();












