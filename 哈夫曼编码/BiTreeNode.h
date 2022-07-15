//#define 
#define _CRT_SECURE_NO_WARNINGS

#pragma once
//BITREENODE.H


#include<iostream>
using namespace std;

static struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* leftNode;
	BinaryTreeNode* rightNode;
	BinaryTreeNode* parent;
};


class BinaryTree
{
private:
	BinaryTreeNode* root;
	string Code[29];

	void preTraversal();	//ǰ�������
	int nodeCount();	//����ڵ�����
	//int treeHight(BinaryTreeNode*& root);	//���������
	int getLeavesCount();	//����Ҷ�Ӹ���;
	void select_minium(BinaryTreeNode* root, int &i, int &min1, int &min2);
	int min(BinaryTreeNode* root, int& i);
public:
	BinaryTree(const int charNumber[],int n);	//����������
	//BinaryTree();
	~BinaryTree();
	
	string getCode(int i);
	string getHuffmanCode(char ch);	//��ȡch��Huffman����

};

