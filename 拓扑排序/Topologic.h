#pragma once

#include "Gragh.h"

struct TreeNode
{
	char ch;
	Gragh gragh;
	TreeNode* parent;
	vector<TreeNode*> children;
	
};

class Topologic
{
public:
	Topologic(Gragh gragh);
	void sort();
	void dfsPrint(TreeNode* root,vector<char>& number);
	void printLine(vector<char>& number);

private:
	int getInDegree(Gragh gragh,char ch);
	Gragh deleteNode(Gragh gragh,char ch);
	void sort(TreeNode* root);

private:
	TreeNode* head;
	int circleNumber;
};

