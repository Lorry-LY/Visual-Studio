#include"BiTreeNode.h"
#include<iostream>
#include<fstream>
using namespace std;

static bool init(string filename, int charNumber[])
{
	fstream file(filename,ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			char ch;
			file >> ch;
			if ('a' <= ch && ch <= 'z')
			{
				charNumber[ch - 'a']++;
			}
			else if (',' == ch)
			{
				charNumber[27]++;
			}
			else if ('.' == ch)
			{
				charNumber[28]++;
			}
			else if (' ' == ch)
			{
				charNumber[26]++;
			}
		}
		file.close();
		return true;
	}
	else
	{
		cout << "文件打开失败。" << endl;
		return false;
	}
}

static bool save(string in_filename,string out_filename,BinaryTree* root)
{
	string temp = "";
	fstream file(in_filename, ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			char ch;
			file >> ch;
			temp += ch;
		}
		file.close();
		fstream out_file(out_filename, ios::out);
		if (out_file.is_open())
		{
			for (int i = 0; i < temp.size(); i++)
			{
				if ('a' <= temp[i] && temp[i] <= 'z')
				{
					out_file << root->getCode(temp[i] - 'a');
				}
				else if (',' == temp[i])
				{
					out_file << root->getCode(27);
				}
				else if ('.' == temp[i])
				{
					out_file << root->getCode(28);
				}
				else if (' ' == temp[i])
				{
					out_file << root->getCode(26);
				}
			}
			out_file.close();
		}
		else
		{
			cout << "文件保存失败。" << endl;
			return false;
		}


		return true;
	}
	else
	{
		cout << "文件保存失败。" << endl;
		return false;
	}
}

static bool transTable(BinaryTree* root)
{
	fstream file("transTable.txt", ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < 26; i++)
		{
			char ch = i + 'a';
			file << ch << " " << root->getCode(i) << endl;
		}
		file << ',' << " " << root->getCode(27) << endl;
		file << '.' << " " << root->getCode(28) << endl;
		file << ' ' << " " << root->getCode(26) << endl;
		file.close();
		
	}
	else
	{
		cout << "转化文件保存失败。" << endl;
		return false;
	}
	return true;
}

static double Compare(string in_filename, string out_filename)
{
	FILE* file = fopen(in_filename.c_str(), "r");
	if (!file)return 0;
	fseek(file, 0L, SEEK_END);
	int in_size = ftell(file);
	fclose(file);
	FILE* out_file = fopen(out_filename.c_str(), "r");
	if (!out_file)return 0;
	fseek(out_file, 0L, SEEK_END);
	int out_size = ftell(out_file);
	fclose(out_file);
	return out_size / in_size;
}