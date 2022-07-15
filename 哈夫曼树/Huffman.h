#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct Node			//���ڵ�
{
	int value = -1;		//����ֵ
	int weight = -1;	//Ȩ��
	Node* parent = NULL;	//���ڵ�
	Node* leftChild = NULL;	//����
	Node* rightChild = NULL;//�Һ���
};
inline bool cmp(Node* left, Node* right)		//����>������
{
	return left->weight > right->weight;
}
inline bool cmpEqual(Node* left, Node* right)	//����>=������
{
	return left->weight >= right->weight;
}


class Huffman
{
public:
	Huffman();
	Huffman(string filename);		//���캯��
	void encode();					//���뺯��
	void saveFile(string filename);	//����ѹ���ļ�
	void decode(string filename);	//����
	void printEfficiency();			//�����ѹ��

private:
	Node* createTree(vector<Node*> node);					//����
	vector<Node*> getVector(string str);					//��ȡԴ�ļ����ַ��ڵ�
	void insertSort(vector<Node*>& nodes, Node* newNode);	//��������
	void post_order(Node* root, ofstream& file);			//�������

private:
	string inputFile;			//�����ļ���
	string outputFile;			//����ļ���
	long inputFileLength;		//�����ļ���С
	long outputFileLength;		//����ļ���С
	Node* root;					//���ڵ�
	map<char, string> encodeTable;	//�����
	map<string, char> decodeTable;	//�����
};

