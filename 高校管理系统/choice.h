#pragma once
//函数声明部分,
//第一部分是所有涉及到列出菜单的函数choice，
//第二部分是所有选项中涉及对信息进行操作(如排序，查找)的函数operate
//第三部分是所有涉及到输出数据到屏幕上的的函数print

//生成菜单并读入用户的选项,再进入到用户所选的分支中执行相应功能

void choice0();
//主菜单第一选项：统计
void choice1();
void choice1_1();

void choice1_2();
void choice1_2_1();
void choice1_2_2();
void choice1_2_3();
void choice1_2_4();

void choice1_3();

//主菜单第二选项：增加
void choice2();

//主菜单第三选项：查找
void choice3();
void choice3_1();
void choice3_2();



//对数据进行操作，并回传结果
void operate1_1_1();
void operate1_1_2();

void operate1_2_1_1();
void operate1_2_1_2();

void operate1_2_2_1();
void operate1_2_2_2();

void operate1_2_3_1();
void operate1_2_3_2();
void operate1_2_3_3();
void operate1_2_3_4();

void operate1_2_4_1();
void operate1_2_4_2();

void operate2_1();//这一系列operate是添加各种东西,涉及到在屏幕上输出语句
void operate2_2();
void operate2_3();
void operate2_4();
void operate2_5();
void operate2_6();
void operate2_7();
void operate2_8();
void operate2_9();

void operate3_1_1();//operate3_1 和3_2 涉及到对人猿信息编辑修改删除，需要在屏幕上输出语句
void operate3_1_2();
void operate3_2_1();
void operate3_2_2();

void operate3_3();//3_3及以后的不涉及输出语句，得到目标的下标保存在vec_int3[0]中
void operate3_4();
void operate3_5();
void operate3_6();
void operate3_7();


//如果涉及到排序查找等operate，则根据operate最后修改的全局变量进行输出
//如不涉及，则直接从全局变量中提取数据进行输出
void print1_1();
void print1_1_1();
void print1_1_2();

void print1_2_1();
void print1_2_1_1();
void print1_2_1_2();

void print1_2_2();
void print1_2_2_1();
void print1_2_2_2();

void print1_2_3();
void print1_2_3_1();
void print1_2_3_2();
void print1_2_3_3();
void print1_2_3_4();

void print1_2_4();
void print1_2_4_1();
void print1_2_4_2();

void print1_3();

void print3_1();
void print3_2();
void print3_3();
void print3_4();
void print3_5();
void print3_6();
void print3_7();
