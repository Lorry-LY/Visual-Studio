//BITREENODE.CPP

#include "BiTreeNode.h"

BinaryTree::~BinaryTree()
{
	
	//delete root;
}

BinaryTree::BinaryTree(const int charNumber[],int n)
{
	int total = 2 * n - 1;
	int i;
	root = new BinaryTreeNode();
	if (!root)
	{
		cout << "哈夫曼数建立失败。" << endl;
		return;
	}
	
	for (i = 0; i < n; i++)
	{
		root[i].data = charNumber[i];
		root[i].leftNode = NULL;
		root[i].rightNode = NULL;
		root[i].parent = NULL;
	}
	for (; i < total; i++)
	{
		root[i].data = 0;
		root[i].leftNode = NULL;
		root[i].rightNode = NULL;
		root[i].parent = NULL;
	}
	int min1, min2;
	for (i = n; i < total; i++)
	{
		select_minium(root, i, min1, min2);
		root[min1].parent = &root[i];
		root[min2].parent = &root[i];
		root[i].leftNode = &root[min1];
		root[i].rightNode = &root[min2];
		root[i].data = root[min1].data + root[min2].data;
	}

	for (i = 0; i < n; i++)
	{
		BinaryTreeNode* current = &root[i];
		BinaryTreeNode* father = root[i].parent;
		

		while (father != NULL)
		{
			if (father->leftNode == current)
			{
				Code[i].append("0");
			}
			else
			{
				Code[i].append("1");
			}
			
			current = father;
			father = father->parent;
		}
		current = NULL;
		father = NULL;
		//_strrev(Code[i]);
		reverse(Code[i].begin(), Code[i].end());
	}
	

}

void BinaryTree::select_minium(BinaryTreeNode* root, int& i, int& min1, int& min2)
{
	min1 = min(root, i);
	min2 = min(root, i);
}

int BinaryTree::min(BinaryTreeNode* root, int& i)
{
	int j = 0;
	int min_number;
	int min_data;
	while (root[j].parent != NULL)j++;
	min_data = root[j].data;
	min_number = j;
	for (j++; j < i; j++)
	{
		if (root[j].data < min_data && root[j].parent == NULL)
		{
			min_data = root[j].data;
			min_number = j;
		}
	}
	root[min_number].parent = &root[0];
	return min_number;
}

void BinaryTree::preTraversal()
{

}

int  BinaryTree::nodeCount()
{
	return -1;
}


int BinaryTree::getLeavesCount()
{
	return -1;
}

string BinaryTree::getHuffmanCode(char ch)
{
	if ('a' <= ch && ch <= 'z')
	{
		return Code[(int)(ch - 'a')];
	}
	else if (',' == ch)
	{
		return Code[27];
	}
	else if ('.' == ch)
	{
		return Code[28];
	}
	else if (' ' == ch)
	{
		return Code[26];
	}
	else {
		cout << "无对应编码。" << endl;
	}
}

string BinaryTree::getCode(int i)
{
	return Code[i];
}