#pragma once
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
	double data;		//节点值
	int weight;			//权重
	TreeNode* parent;	//父节点
	TreeNode* left;		//左节点
	TreeNode* right;	//右节点
};

class ZhongZhui
{
public:
	ZhongZhui(string str);

	void PreOrderTraverse(TreeNode*);		//中序遍历
	void FrontOrderTraverse(TreeNode*);		//前序遍历
	TreeNode* getRoot();					//获取根节点
	double getResult(TreeNode* root);		//得到计算结果
	double calculateStep(double number1, double op, double number2);	//单步计算


private:
	TreeNode* root;		//根节点
	vector<TreeNode*>options;	//符号栈
	vector<TreeNode*>numbers;		//数字栈
};

