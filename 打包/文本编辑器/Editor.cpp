//Editor.cpp

#include "Editor.h"
#include<stdio.h>

bool Editor::UserSaysYes()
{
	cout << "��ȷ���𣿣�y��ʾȷ������";
	char ch;
	cin >> ch;
	getchar();
	if ('y' == ch)
	{
		return true;
	}
	return false;
}

bool Editor::NextLine()  //ת����һ��
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
	cout << "��������Ҫ��ת��������";
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
	cout << "�������µ��ı���" << endl;
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
	cout << "�������滻���ı���" << endl;
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
	cout << "�����롾·����+�ļ���+��չ����" << endl;
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
		cout << "�ļ���ȡ�ɹ���" << endl;
	}
	else
	{
		cout << "�ļ���ȡʧ��" << endl;
	}

}



void Editor::WriteFile()
{
	cout << "�����뱣���ļ��ġ�·����+�ļ���+��չ����" << endl;
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
		cout << "�ļ�����ɹ���" << endl;
		f.close();
		
	}
	else
	{
		cout << "�ļ�����ʧ��" << endl;
	}
}

void Editor::FindCharString()
{
	cout << "������Ҫ���ҵ��ı�";
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
		cout << "û���ҵ���Ӧ���ı���" << endl;
	}
	else
	{
		cout << "��Ӧ�ı���λ���ڸ��е�" << position << "����" << endl;
	}


}

void Editor::View()
{
	if (textBuffer.empty())
	{
		cout << "��ǰ�ı�Ϊ�ա�" << endl;
		return;
	}
	cout << "�ı�����Ϊ��" << endl;
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
			cout << "�ļ�����ɹ���" << endl;
			f.close();
		}
		else
		{
			cout<< "�ļ�����ʧ��"<<endl;
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
			cout << "�ı��򿪳ɹ���" << endl;
			if (textBuffer.size() != 0)
			{
				cout << "�ı�����Ϊ��" << endl;
				list<CharString>::iterator it = textBuffer.begin();
				for (int i = 0; i < textBuffer.size(); i++,it++)
				{
					cout << i + 1 << ":" << it->ToCStr()<<endl;
				}
			}
			else
			{
				cout << "�ı�����Ϊ�ա�" << endl;
			}
			
			//cout << (int)input.is_open();
		}
		else
		{
			string str = "�ļ���ʧ�ܡ�";
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
	//��ӡ����
	CharString curLine;
	list<CharString>::iterator it = textBuffer.begin();
	for (int i = 0; i < curLineNo-1; i++)
	{
		it++;
	}
	if (curLineNo != 0)
	{
		cout << endl << "��ǰ��" << curLineNo << "�е�����Ϊ��";
		curLine = *(it);
		cout << curLine.ToCStr() << endl;
		cout << "������ָ�";
	}
	else
	{
		cout << "�ļ�����Ϊ�ա�" << endl;
		cout << "������ָ�";
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
			cout << "���棺�ı�����Ϊ��" << endl;
		}
		else
		{
			curLineNo = 1;
		}
		break;
	case 'c':
		if (textBuffer.empty())
		{
			cout << "���棺�ı�����Ϊ��" << endl;
		}
		else if (!ChangeLine())
		{
			cout << "���棺����ʧ��" << endl;
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
			cout << "���棺�ı�����Ϊ��" << endl;
		}
		else
		{
			curLineNo = textBuffer.size();
		}
		break;
	case 'f':
		if (textBuffer.empty())
		{
			cout << "���棺�ı�����Ϊ��" << endl;
		}
		else
		{
			FindCharString();
		}
		break;
	case 'g':
		if (!GotoLine())
		{
			cout << "ת����ʧ��" << endl;
		}
		break;
	case '?':
	case 'h':cout << "��Ч�����ַ���" << endl;
		cout << "*****************************************************************" << endl;
		cout << "*    b(ת����һ��)    c(�޸ĵ�ǰ���ı�����)    d(ɾ����ǰ��)    *" << endl;
		cout << "*    e(ת�����һ��)  f(�����ı�λ��)          g(ת��ĳ��)      *" << endl;
		cout << "*    ?(����)          h(����)                  i(����һ��)      *" << endl;
		cout << "*    n(ת����һ��)    p(ת����һ��)            r(��ȡ���ļ�)    *" << endl;
		cout << "*    v(��ʾ�ı�����)  w(�����ļ�)                               *" << endl;
		cout << "*****************************************************************" << endl;
		break;
	case 'i':
		if (!insertLine())
		{
			cout << "���󣺲���ʧ��" << endl;
		}
		break;
	case 'n':
		if (!NextLine())
		{
			cout << "���󣬲���ʧ��" << endl;
		}
		break;
	case 'p':
		if (!PreviousLine())
		{
			cout << "���󣬲���ʧ��" << endl;
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
			cout << "���棺�ı�����Ϊ��" << endl;
		}
		else
		{
			WriteFile();
		}
		break;
	default:
		cout << "����h���ߣ���ȡ������������Ч�����ַ���" << endl;
		break;
	}
}