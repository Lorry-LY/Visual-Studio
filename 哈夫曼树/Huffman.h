#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct Node			//数节点
{
	int value = -1;		//数据值
	int weight = -1;	//权重
	Node* parent = NULL;	//父节点
	Node* leftChild = NULL;	//左孩子
	Node* rightChild = NULL;//右孩子
};
inline bool cmp(Node* left, Node* right)		//重载>操作符
{
	return left->weight > right->weight;
}
inline bool cmpEqual(Node* left, Node* right)	//重载>=操作符
{
	return left->weight >= right->weight;
}


class Huffman
{
public:
	Huffman();
	Huffman(string filename);		//构造函数
	void encode();					//编码函数
	void saveFile(string filename);	//保存压缩文件
	void decode(string filename);	//解码
	void printEfficiency();			//输出解压率

private:
	Node* createTree(vector<Node*> node);					//建树
	vector<Node*> getVector(string str);					//获取源文件各字符节点
	void insertSort(vector<Node*>& nodes, Node* newNode);	//插入排序
	void post_order(Node* root, ofstream& file);			//后序遍历

private:
	string inputFile;			//输入文件名
	string outputFile;			//输出文件名
	long inputFileLength;		//输入文件大小
	long outputFileLength;		//输出文件大小
	Node* root;					//根节点
	map<char, string> encodeTable;	//编码表
	map<string, char> decodeTable;	//解码表
};

