#pragma once
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
	double data;		//�ڵ�ֵ
	int weight;			//Ȩ��
	TreeNode* parent;	//���ڵ�
	TreeNode* left;		//��ڵ�
	TreeNode* right;	//�ҽڵ�
};

class ZhongZhui
{
public:
	ZhongZhui(string str);

	void PreOrderTraverse(TreeNode*);		//�������
	void FrontOrderTraverse(TreeNode*);		//ǰ�����
	TreeNode* getRoot();					//��ȡ���ڵ�
	double getResult(TreeNode* root);		//�õ�������
	double calculateStep(double number1, double op, double number2);	//��������


private:
	TreeNode* root;		//���ڵ�
	vector<TreeNode*>options;	//����ջ
	vector<TreeNode*>numbers;		//����ջ
};

