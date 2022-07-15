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

	void preTraversal();	//前序遍历；
	int nodeCount();	//计算节点总数
	//int treeHight(BinaryTreeNode*& root);	//计算数深度
	int getLeavesCount();	//计算叶子个数;
	void select_minium(BinaryTreeNode* root, int &i, int &min1, int &min2);
	int min(BinaryTreeNode* root, int& i);
public:
	BinaryTree(const int charNumber[],int n);	//创建二叉树
	//BinaryTree();
	~BinaryTree();
	
	string getCode(int i);
	string getHuffmanCode(char ch);	//获取ch的Huffman编码

};

