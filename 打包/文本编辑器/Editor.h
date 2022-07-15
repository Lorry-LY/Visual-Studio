//Editor.h
//Editor.h

#include"CharString.h"

#pragma once
class Editor
{
private:
	
	list<CharString>textBuffer;		//文本缓存
	int curLineNo;	//当前行号
	string infile;	//输入文件
	string outfile;	//输出文件
	char userCommand;	//用户命令

	bool UserSaysYes();	//用户回答Yes或者No
	bool NextLine();	//转到下一行
	bool PreviousLine();	//转到上一行
	bool GotoLine();	//转到指定行
	bool insertLine();	//插入一行
	bool ChangeLine();	//替换当前指定行文本串

	void ReadFile();	//读入文本信息
	void WriteFile();	//写文本文件
	void FindCharString();	//查找串
	void View();	//查看缓冲区

public:
	Editor(string inName, string outName);	//构造函数
	~Editor();	//析构函数
	bool GetCommand();	//读取操作命令字符usercommand
	void RunCommand();	//运行操作命令
};

