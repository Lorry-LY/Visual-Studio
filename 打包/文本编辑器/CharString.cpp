#include "CharString.h"

CharString::CharString()
{
	length = 0;
	strVal = new char[length + 1];
	strVal[length] = '\0';
}

CharString::~CharString()
{
	/*if (strVal != NULL)
	{
		delete strVal;
		strVal = NULL;
	}*/
}

CharString::CharString(const CharString& sourse)
{
	length = strlen(sourse.ToCStr());
	if (strVal != NULL)
	{
		//delete strVal;
		strVal = NULL;
	}
	strVal = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		strVal[i] = sourse[i];
	}
	strVal[length] = '\0';

}

CharString::CharString(const char* sourse)
{
	length = strlen(sourse);
	if (strVal != NULL)
	{
		//delete strVal;
		strVal = NULL;
	}
	strVal = new char[length + 1];
	strcpy(strVal, sourse);
	strVal[length] = '\0';
}

CharString::CharString(list<char>& copy)
{
	length = copy.size();
	if (strVal != NULL)
	{
		//delete strVal;
		strVal = NULL;
	}
	strVal = new char[length + 1];
	list<char>::iterator it=copy.begin();
	for (int i = 0; i < length; i++)
	{
		strVal[i] = *it++;
	}
	strVal[length] = '\0';
}

int CharString::Length() const
{
	int count = 0;
	while (*(strVal+count) != '\0')
	{
		count++;
	}
	return count;
}

bool CharString::Empty() const
{
	return strVal[0] == '\0';
}

CharString& CharString::operator =(const CharString& sourse)
{
	length = strlen(sourse.ToCStr());
	if (strVal != NULL)
	{
		delete strVal;
		strVal = NULL;
	}
	strVal = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		*(strVal+i) = sourse[i];
	}
	strVal[length] = '\0';
	return *this;
}

const char* CharString::ToCStr() const
{
	return (const char*)strVal;
}

const char& CharString::operator [](int i) const
{
	return *(strVal + i);
}

CharString CharString::Read(fstream& input)
{
	string str;
	getline(input, str);
	if (strVal != NULL)
	{
		delete strVal;
		strVal = NULL;
	}
	strVal = new char[str.size() + 1];
	length = str.size();
	for (int i = 0; i < str.size(); i++)
	{
		*(strVal + i) = str[i];
	}
	*(strVal + str.size()) = '\0';
	return *this;
}

CharString CharString::Read(fstream& input, char& terminalChar)
{
	string str;
	getline(input, str);
	if (strVal != NULL)
	{
		delete strVal;
		strVal = NULL;
	}
	strVal = new char[str.size() + 1];
	length = str.size();
	for (int i = 0; i < str.size(); i++)
	{
		*(strVal + i) = str[i];
	}
	strVal[length] = '\0';
	terminalChar = strVal[length - 1];
	return *this;
	
}

void CharString::Write(fstream& output)
{
	const char* c = this->ToCStr();
	string str = c;
	delete[]c;
	output << str << endl;
}

void CharString::Concat(CharString& addTo, const CharString& addOn)
{
	const char* cFirst = addTo.ToCStr();
	const char* cSecond = addOn.ToCStr();
	char* c = new char[strlen(cFirst) + strlen(cSecond) + 1];
	strcpy(c, cFirst);
	strcat(c, cSecond);
	addTo = c;
	delete[]c;
}

void CharString::Copy(CharString& copy, const CharString& original)
{	
	length = strlen(original.ToCStr());
	for (int i = 0; i < length; i++)
	{
		*(strVal + i) = original[i];
	}
}

void CharString::Copy(CharString& copy, const CharString& original, int n)
{
	length = n ;
	for (int i = 0; i < n; i++)
	{
		*(strVal + i) = original[i];
	}
}

int CharString::Index(const CharString& target, const CharString& pattern, int pos)
{
	const int MAXLEN = 50;
	int next[MAXLEN] = { 0 };
	int nextval[MAXLEN] = { 0 };
	CharString::get_next(next, pattern.ToCStr());
	return CharString::kmp(target.ToCStr(), pattern.ToCStr(), next);
}

void CharString::get_next(int next[],const char s[])
{
	int lens = strlen(s);
	int i = 0;
	int j = -1;
	next[0] = -1;
	while (i < lens)
	{
		if (j == -1 || s[j] == s[i])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int CharString::kmp(const char s1[],const char s2[], int next[])
{
	int lens1 = strlen(s1);
	int lens2 = strlen(s2);
	int i = 0, j = 0;
	while (i < lens1 && j < lens2)
	{
		if (j == -1 || s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == lens2)
	{
		return i - j + 1;
	}
	else
	{
		return -1;
	}
}

CharString CharString::SubCharString(const CharString& s, int pos, int len)
{
	int len1 = strlen(s.ToCStr());
	int leng = pos + len > len1 ? len1 : pos + len;
	string str="";
	for (int i = pos; i < leng; i++)
	{
		str += s[i];
	}
	return CharString(str.c_str());
}

bool operator ==(const CharString& first, const CharString& second)	//重载操作符==
{
	return strcmp(first.ToCStr(), second.ToCStr());
}
bool operator <(const CharString& first, const CharString& second)	//重载操作符<
{
	return strcmp(first.ToCStr(), second.ToCStr()) < 0;
}
bool operator >(const CharString& first, const CharString& second)	//重载操作符>
{
	return strcmp(first.ToCStr(), second.ToCStr()) > 0;
}
bool operator <=(const CharString& first, const CharString& second)	//重载操作符<=
{
	return strcmp(first.ToCStr(), second.ToCStr()) <= 0;
}
bool operator >=(const CharString& first, const CharString& second)	//重载操作符>=
{
	return strcmp(first.ToCStr(), second.ToCStr()) >= 0;
}
bool operator !=(const CharString& first, const CharString& second)	//重载操作符!=
{
	return strcmp(first.ToCStr(), second.ToCStr()) != 0;
}