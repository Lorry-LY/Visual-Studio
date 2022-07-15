//CharString.h

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<sstream>
#include<List>
using namespace std;

#pragma once
class CharString
{
protected:
	char* strVal;	//串值
	int length;		//串长

public:
	CharString();	//构造函数
	virtual ~CharString();	//析构函数
	CharString(const CharString& sourse);	//复制函数
	CharString(const char* sourse);	//C转化未来的函数
	CharString(list<char>& copy);	//从链表转化为的构造函数
	int Length() const;	//求串长度
	bool Empty() const;	//判断串是否为空
	CharString& operator =(const CharString& sourse);	//重载赋值运算符
	const char* ToCStr() const;	//转化为C风格字符串
	const char& operator [](int i) const;	//重载下标运算符
	CharString Read(fstream& input);	//从输入流中读入串
	CharString Read(fstream& input, char& terminalChar);	//从输入流读入串，用terminalChar返回串结束字符
	void Write(fstream& output);	//输出串
	void Concat(CharString& addTo, const CharString& addOn);//将串addon连接到addto串的后面
	void Copy(CharString& copy, const CharString& original);	//将串original复制到串COPY
	void Copy(CharString& copy, const CharString& original, int n);	//将串original复制n个字符到串COPY
	int Index(const CharString& target, const CharString& pattern, int pos = 0);	//查找模式串pattern第一次在目标串中出现的位置。
	CharString SubCharString(const CharString& s, int pos, int len);	//求串s的第pos个字符开始为长度len的子串。

private:
	void get_next(int next[],const char s[]);	//KMP算法求next数组函数
	int kmp(const char s1[],const char s2[], int next[]);	//Kmp算法

};

bool operator ==(const CharString& first, const CharString& second);	//重载操作符==
bool operator <(const CharString& first, const CharString& second);	//重载操作符<
bool operator >(const CharString& first, const CharString& second);	//重载操作符>
bool operator <=(const CharString& first, const CharString& second);	//重载操作符<=
bool operator >=(const CharString& first, const CharString& second);	//重载操作符>=
bool operator !=(const CharString& first, const CharString& second);	//重载操作符!=
