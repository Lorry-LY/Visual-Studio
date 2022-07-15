#include "Topologic.h"

Topologic::Topologic(Gragh gragh)
{
	vector<TreeNode*> temp;
	head = new TreeNode{ ' ' ,gragh,NULL,temp };
	circleNumber = 0;
}

void Topologic::sort()
{
	sort(head);
	vector<char> number;
	cout << "\n拓扑排序" << endl;
	dfsPrint(head,number);
	if (circleNumber == 1)
	{
		cout << "该图存在环路，无法得到拓扑排序。" << endl;
	}
}

void Topologic::printLine(vector<char>& number)
{
	for (int i = 1; i < number.size(); i++)
	{
		cout << number[i];
	}
	cout << endl;
}

void Topologic::dfsPrint(TreeNode* root, vector<char>& number)
{
	number.push_back(root->ch);
	if (root->children.size() == 0)
	{
		circleNumber++;
		printLine(number);
	}
	for (int i = 0; i < root->children.size(); i++)
	{
		dfsPrint(root->children[i], number);
	}
	number.pop_back();
	if (root->gragh.nodes.size() == 0);
}

void Topologic::sort(TreeNode* root)
{
	if (root->gragh.nodes.size() == 0);
	int i = 0;
	for (; i < root->gragh.nodes.size(); i++)
	{
		if (getInDegree(root->gragh, root->gragh.nodes[i]) == 0)
		{
			vector<TreeNode*> temp;
			TreeNode* newNode = new TreeNode{ root->gragh.nodes[i] ,deleteNode(root->gragh, root->gragh.nodes[i]),root,temp };
			root->children.push_back(newNode);
			sort(newNode);
		}
	}
}

int Topologic::getInDegree(Gragh gragh, char ch)
{
	int inDegree = 0;
	for (int i = 0; i < gragh.sides.size(); i++)
	{
		if (gragh.sides[i].second == ch)
		{
			inDegree++;
		}
	}
	return inDegree;
}

Gragh Topologic::deleteNode(Gragh gragh, char ch)
{
	Gragh result;
	for (int i = 0; i < gragh.sides.size(); i++)
	{
		if (gragh.sides[i].first != ch)
		{
			result.sides.push_back(gragh.sides[i]);
		}
	}
	for (int i = 0; i < gragh.nodes.size(); i++)
	{
		if (ch != gragh.nodes[i])
		{
			result.nodes.push_back(gragh.nodes[i]);
		}
	}
	return result;
}

