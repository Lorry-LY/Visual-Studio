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
	char* strVal;	//��ֵ
	int length;		//����

public:
	CharString();	//���캯��
	virtual ~CharString();	//��������
	CharString(const CharString& sourse);	//���ƺ���
	CharString(const char* sourse);	//Cת��δ���ĺ���
	CharString(list<char>& copy);	//������ת��Ϊ�Ĺ��캯��
	int Length() const;	//�󴮳���
	bool Empty() const;	//�жϴ��Ƿ�Ϊ��
	CharString& operator =(const CharString& sourse);	//���ظ�ֵ�����
	const char* ToCStr() const;	//ת��ΪC����ַ���
	const char& operator [](int i) const;	//�����±������
	CharString Read(fstream& input);	//���������ж��봮
	CharString Read(fstream& input, char& terminalChar);	//�����������봮����terminalChar���ش������ַ�
	void Write(fstream& output);	//�����
	void Concat(CharString& addTo, const CharString& addOn);//����addon���ӵ�addto���ĺ���
	void Copy(CharString& copy, const CharString& original);	//����original���Ƶ���COPY
	void Copy(CharString& copy, const CharString& original, int n);	//����original����n���ַ�����COPY
	int Index(const CharString& target, const CharString& pattern, int pos = 0);	//����ģʽ��pattern��һ����Ŀ�괮�г��ֵ�λ�á�
	CharString SubCharString(const CharString& s, int pos, int len);	//��s�ĵ�pos���ַ���ʼΪ����len���Ӵ���

private:
	void get_next(int next[],const char s[]);	//KMP�㷨��next���麯��
	int kmp(const char s1[],const char s2[], int next[]);	//Kmp�㷨

};

bool operator ==(const CharString& first, const CharString& second);	//���ز�����==
bool operator <(const CharString& first, const CharString& second);	//���ز�����<
bool operator >(const CharString& first, const CharString& second);	//���ز�����>
bool operator <=(const CharString& first, const CharString& second);	//���ز�����<=
bool operator >=(const CharString& first, const CharString& second);	//���ز�����>=
bool operator !=(const CharString& first, const CharString& second);	//���ز�����!=
