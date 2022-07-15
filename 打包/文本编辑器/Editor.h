//Editor.h
//Editor.h

#include"CharString.h"

#pragma once
class Editor
{
private:
	
	list<CharString>textBuffer;		//�ı�����
	int curLineNo;	//��ǰ�к�
	string infile;	//�����ļ�
	string outfile;	//����ļ�
	char userCommand;	//�û�����

	bool UserSaysYes();	//�û��ش�Yes����No
	bool NextLine();	//ת����һ��
	bool PreviousLine();	//ת����һ��
	bool GotoLine();	//ת��ָ����
	bool insertLine();	//����һ��
	bool ChangeLine();	//�滻��ǰָ�����ı���

	void ReadFile();	//�����ı���Ϣ
	void WriteFile();	//д�ı��ļ�
	void FindCharString();	//���Ҵ�
	void View();	//�鿴������

public:
	Editor(string inName, string outName);	//���캯��
	~Editor();	//��������
	bool GetCommand();	//��ȡ���������ַ�usercommand
	void RunCommand();	//���в�������
};

