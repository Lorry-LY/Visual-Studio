#include "Huffman.h"

int main()
{
	string inputFile, encodeFile, decodeFile;
	cout << "������Դ�ļ����ƣ�";
	cin >> inputFile;
	cout << "������ѹ���ļ����ƣ�";
	cin >> encodeFile;
	cout << "����������ļ����ƣ�";
	cin >> decodeFile;
	Huffman f(inputFile);		//������������
	f.encode();					//����������
	f.saveFile(encodeFile);		//���������ļ�
	f.decode(decodeFile);		//����
	f.printEfficiency();		//���ѹ����
	return 0;
}