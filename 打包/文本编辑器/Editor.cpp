//Editor.cpp

#include "Editor.h"
#include<stdio.h>

bool Editor::UserSaysYes()
{
	cout << "你确定吗？（y表示确定）：";
	char ch;
	cin >> ch;
	getchar();
	if ('y' == ch)
	{
		return true;
	}
	return false;
}

bool Editor::NextLine()  //转到下一行
{
	if (curLineNo >= textBuffer.size())
	{
		return false;
	}
	curLineNo++;
	return true;
}

bool Editor::PreviousLine()
{
	if (curLineNo <= 1)
	{
		return false;
	}
	curLineNo--;
	return true;
}

bool Editor::GotoLine()
{
	cout << "请输入需要跳转的行数：";
	int row;
	cin >> row;
	getchar();
	if (row<1 || row>textBuffer.size())
	{
		return false;
	}
	curLineNo = row;
	return true;
}

bool Editor::insertLine()
{
	curLineNo++;
	cout << "请输入新的文本：" << endl;
	string str;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		str += ch;
	}
	CharString cs(str.c_str());
	list<CharString>::iterator it = textBuffer.begin();
	for (int i = 0; i < curLineNo - 1; i++)
	{
		it++;
	}
	textBuffer.insert(it, 1, cs);
	return true;
}

bool Editor::ChangeLine()
{
	cout << "请输入替换的文本：" << endl;
	string str;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		str += ch;
	}
	CharString cs(str.c_str());
	list<CharString>::iterator it = textBuffer.begin();
	for (int i = 0; i < curLineNo; i++)
	{
		it++;
	}
	textBuffer.erase(--it);
	it = textBuffer.begin();
	for (int i = 0; i < curLineNo -1; i++)
	{
		it++;
	}
	textBuffer.insert(it, cs);
	return true;

}

void Editor::ReadFile()
{
	cout << "请输入【路径】+文件名+扩展名：" << endl;
	string filename;
	cin >> filename;
	getchar();
	fstream f(filename);
	if (f.is_open())
	{
		textBuffer.clear();
		CharString cs("hello");
		while (!f.eof())
		{
			cs.Read(f);
			textBuffer.push_back(cs);
		}
		f.close();
		curLineNo = 1;
		cout << "文件读取成功。" << endl;
	}
	else
	{
		cout << "文件读取失败" << endl;
	}

}



void Editor::WriteFile()
{
	cout << "请输入保存文件的【路径】+文件名+扩展名：" << endl;
	string filename;
	cin >> filename;
	getchar();
	fstream f(filename,ios::out);
	if (f.is_open())
	{
		list<CharString> temp = textBuffer;
		list<CharString>::iterator it = temp.begin();
		for(int i=0;i< temp.size();i++,it++)
		{
			it->Write(f);
			//textBuffer.pop_front();
			//delete &cs;
		}	
		//delete &temp;
		cout << "文件保存成功。" << endl;
		f.close();
		
	}
	else
	{
		cout << "文件保存失败" << endl;
	}
}

void Editor::FindCharString()
{
	cout << "请输入要查找的文本";
	string str;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		str += ch;
	}	
	CharString c(str.c_str());
	list<CharString>::iterator it = textBuffer.begin();
	for (int i = 0; i < curLineNo - 1; i++)
	{
		it++;
	}
	CharString cs = *it;
	int position = cs.Index(cs, c);
	if (-1 == position)
	{
		cout << "没有找到对应的文本。" << endl;
	}
	else
	{
		cout << "对应文本的位置在改行的" << position << "处。" << endl;
	}


}

void Editor::View()
{
	if (textBuffer.empty())
	{
		cout << "当前文本为空。" << endl;
		return;
	}
	cout << "文本内容为：" << endl;
	list<CharString>::iterator it = textBuffer.begin();
	for (int i = 0; i < textBuffer.size(); i++)
	{
		CharString cs = *(it++);
		cout << i + 1 << ":" << cs.ToCStr() << endl;
	}
	
}

Editor::~Editor()
{
		fstream f(outfile, ios::out);
		if (f.is_open())
		{
			list<CharString> temp = textBuffer;
			list<CharString>::iterator it = temp.begin();
			for (int i = 0; i < temp.size(); i++, it++)
			{
				it->Write(f);
				//textBuffer.pop_front();
				//delete &cs;
			}
			//delete &temp;
			cout << "文件保存成功。" << endl;
			f.close();
		}
		else
		{
			cout<< "文件保存失败"<<endl;
		}
	
}

Editor::Editor(string infName, string outfName)
{
	infile=infName;
	outfile = outfName;
	curLineNo = 0;
	userCommand = 0;
	try
	{
		fstream input(infName,ios::in);
		if (input.is_open())
		{
			textBuffer.clear();
			
			while (!input.eof())
			{
				CharString str;
				str.Read(input);
				textBuffer.push_back(str);
				curLineNo++;
			}
			input.close();
			cout << "文本打开成功！" << endl;
			if (textBuffer.size() != 0)
			{
				cout << "文本内容为：" << endl;
				list<CharString>::iterator it = textBuffer.begin();
				for (int i = 0; i < textBuffer.size(); i++,it++)
				{
					cout << i + 1 << ":" << it->ToCStr()<<endl;
				}
			}
			else
			{
				cout << "文本缓冲为空。" << endl;
			}
			
			//cout << (int)input.is_open();
		}
		else
		{
			string str = "文件打开失败。";
			throw str;
		}
	}
	catch (string)
	{
		throw;
	}
	
}

bool Editor::GetCommand()
{
	//打印函数
	CharString curLine;
	list<CharString>::iterator it = textBuffer.begin();
	for (int i = 0; i < curLineNo-1; i++)
	{
		it++;
	}
	if (curLineNo != 0)
	{
		cout << endl << "当前第" << curLineNo << "行的内容为：";
		curLine = *(it);
		cout << curLine.ToCStr() << endl;
		cout << "请输入指令：";
	}
	else
	{
		cout << "文件缓存为空。" << endl;
		cout << "请输入指令：";
	}
	cin >> userCommand;
	userCommand = tolower(userCommand);
	while (cin.get() != '\n');
	if (userCommand == 'q')
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Editor::RunCommand()
{
	list<CharString>::iterator it = textBuffer.begin();
	switch (userCommand)
	{
	case 'b':
		if (textBuffer.empty())
		{
			cout << "警告：文本缓存为空" << endl;
		}
		else
		{
			curLineNo = 1;
		}
		break;
	case 'c':
		if (textBuffer.empty())
		{
			cout << "警告：文本缓存为空" << endl;
		}
		else if (!ChangeLine())
		{
			cout << "警告：操作失败" << endl;
		}
		break;
	case 'd':
		
		for (int i = 0; i < curLineNo - 1; i++)
		{
			it++;
		}
		textBuffer.erase(it);
		if (textBuffer.empty())
		{
			curLineNo = 0;
		}
		else
		{
			curLineNo=curLineNo==1?1:curLineNo-1;
		}		
		break;
	case 'e':
		if (textBuffer.empty())
		{
			cout << "警告：文本缓冲为空" << endl;
		}
		else
		{
			curLineNo = textBuffer.size();
		}
		break;
	case 'f':
		if (textBuffer.empty())
		{
			cout << "警告：文本缓存为空" << endl;
		}
		else
		{
			FindCharString();
		}
		break;
	case 'g':
		if (!GotoLine())
		{
			cout << "转到行失败" << endl;
		}
		break;
	case '?':
	case 'h':cout << "有效命令字符：" << endl;
		cout << "*****************************************************************" << endl;
		cout << "*    b(转到第一行)    c(修改当前行文本内容)    d(删除当前行)    *" << endl;
		cout << "*    e(转到最后一行)  f(查找文本位置)          g(转到某行)      *" << endl;
		cout << "*    ?(帮助)          h(帮助)                  i(增加一行)      *" << endl;
		cout << "*    n(转到下一行)    p(转到上一行)            r(读取新文件)    *" << endl;
		cout << "*    v(显示文本内容)  w(保存文件)                               *" << endl;
		cout << "*****************************************************************" << endl;
		break;
	case 'i':
		if (!insertLine())
		{
			cout << "错误：操作失败" << endl;
		}
		break;
	case 'n':
		if (!NextLine())
		{
			cout << "错误，操作失败" << endl;
		}
		break;
	case 'p':
		if (!PreviousLine())
		{
			cout << "错误，操作失败" << endl;
		}
		break;
	case 'r':
		ReadFile();
		break;
	case 'v':
		View();
		break;
	case 'w':
		if (textBuffer.empty())
		{
			cout << "警告：文本缓存为空" << endl;
		}
		else
		{
			WriteFile();
		}
		break;
	default:
		cout << "输入h或者？获取帮助或输入有效命令字符：" << endl;
		break;
	}
}