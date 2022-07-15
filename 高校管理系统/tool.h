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
	tool系列文件提供操作系统实现的各种功能：
	该头文件仅仅包含声明部分

	1.	读入介于区间[min，max]的值，例如：
	read_in(20,30,"整数值"）将会提示:请输入整数值:
	read_in(2000,9999，"年龄")将会提示:请输入年龄:

	*不符合条件要求或者包含字母,则要求重复输入直至满足.

	2.读入一个字符串，会自动略过空格，后来我发现了.....
	https://www.cnblogs.com/ECJTUACM-873284962/p/11619496.html
	所以并没有这项

	2.  传入参数vector<const char*>代表一个存储着你要列出的选项，
	vector中各个元素为字符串常值，即选项
	效果是在屏幕上逐条显示选项，并返回一个介于各个选项之间的整数。
	例如共有5个选项，则返回值为[1,5]之间的一个整数
	比如要实现一个只有两个选项的菜单:

	vec_words.clear();
	vec_words.push_back("今天就要吃猪肉");
	vec_words.push_back("这食物对勇士没好处");

	reasult = output_list(vec_words);

	屏幕上将显示：

	1.今天就要吃猪肉
	2.这食物对勇士没好处
	请输入你的选项：

	对这个例子来说，reasult只能是1或2,

	*在每次使用前都需要提前将选项按序进入vector
	*使用完成后将会自动清空vector

	3.在一个存储string的vector中搜索一个string，返回目标在其中的下标；
	如果没有找到则返回-1；

	因为所有string的vector的下标为0的都被设置为默认的实例而不是实际的实例；
	例如实验室列表，专业列表，职称（教师类中的tittle而不是研究人员类中的post）列表，行政人员的duty列表
	这些列表（即不同的vector<string>)的第一个元素都被设置为  "未知XX"
	自此之后的每个值才是对应的实验室/专业/职称/duty.....

	4.初始化所有列表（包括库），将每个列表的首个元素置为"未知xxx"的格式，
	同时引入程序设定之初的数个对象，这些对象在函数内部有说明。

	*建议在运行程序之初直接使用统计功能查看这些人员

	5.传入一个string型的vector，先在屏幕上输出提示词A，随后将其中下标为1到结尾的每个元素按序号输出在屏幕上，
	，最后输出提示词B，执行结束后回传一个[1，vec.size()- 1 + 1]之间的值，用于构造一些菜单。
	特别的：如设置B为"back"，将输出:vec.size().返回上一级
	如设置B为其他关键词则将按真正的传入字符串输出;

	*用于查找

	6.7.用两种方式查找一个人，找到了，则返回1，同时在vec_int3[0]和vec_int3[1]中各存储一个数，
	前者代表人员种类，1 = official，2 = teacher，3 = tea_off, 4 = reasecher
	后者代表在对应的对象列表中的下标

	8.存档，默认保存在D:\\system.txt中

	...
*/


int read_int(int min, int max, const char* key_words);
int output_list(vector<const char*>& vec_list);//引用传值以确保用后清空
int find(vector<string> a_vec_to_be_find, string str_you_want_find);
void creat_all(void);
int choose_list(vector<string> a_str_vec_to_create_list, const char* Akey_words, const char* Bkey_words);
bool find_people_in_number();
bool find_people_in_name();

void information_save();












