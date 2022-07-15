#include "ZhongZhui.h"

ZhongZhui::ZhongZhui(string str)
{
	int num = 1;			//运算符当前权重
	int maxNum = num;		//运算符最大权重
	int minNum = num;		//运算符最小权重
	for (int i = 0; i < str.length() - 1; i++)
	{
		if ('0' <= str[i] && str[i] <= '9')		//数字
		{
			int q = i + 1;
			int numb = 0;
			while ('0' <= str[q] && str[q] <= '9')q++;
			int len = q - i;
			for (int j = 0; j < q - i; j++)
			{
				numb += (str[i + j] - '0') * pow(10, len-1-j);
			}
			i = q - 1;		//构造数字节点
			TreeNode* number = new TreeNode({ 1.0 * numb ,-1,NULL,NULL,NULL});
			numbers.push_back(number);
		}
		else		//字符
		{
			if (str[i] == '(') {		//左括号增加运算符优先级
				if (++num > maxNum) {
					maxNum = num;
				}
			}
			else if (str[i] == ')') {		//右括号减小运算符优先级
				if (--num < minNum) {
					minNum = num;
				}
			}
			else {			//构造运算符节点
				TreeNode* option = new TreeNode({ 1.0 * str[i],num,NULL,NULL,NULL });
				options.push_back(option);
			}
		}
	}
	for (int i = maxNum; i >= minNum; i--)		//从最高优先级的运算符开始构造节点
	{
		char op[4] = { '/','*','-','+' };
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < options.size(); k++)
			{
				if (i == options[k]->weight && options[k]->data == op[j])
				{
					if (numbers[k]->parent == NULL) {
						options[k]->left = numbers[k];
						numbers[k]->parent = options[k];
					}
					else		//如果数节点的父节点不为空，则寻址到其根节点
					{
						TreeNode* temp = numbers[k]->parent;
						while (temp->parent != NULL)
						{
							temp = temp->parent;
						}
						options[k]->left = temp;
						temp->parent = options[k];
					}
					if (numbers[k + 1]->parent == NULL) {
						options[k]->right = numbers[k + 1];
						numbers[k + 1]->parent = options[k];
					}
					else		//如果数节点的父节点不为空，则寻址到其根节点
					{
						TreeNode* temp = numbers[k + 1]->parent;
						while (temp->parent != NULL)
						{
							temp = temp->parent;
						}
						options[k]->right = temp;
						temp->parent = options[k];
					}
				}
			}
		}
	}

	/*根节点初赋值*/
	TreeNode* temp = numbers[0]->parent;
	while (temp->parent != NULL)
	{
		temp = temp->parent;
	}
	root = temp;
}

/*中序遍历*/
void ZhongZhui::PreOrderTraverse(TreeNode* root)
{
	if (root)
	{
		PreOrderTraverse(root->left);//访问该结点的左孩子
		// 操作节点方法，这里只做读取输出用
		if (root->weight != -1)cout << (char)root->data;
		else cout << (int)root->data;
		PreOrderTraverse(root->right);//访问该结点的右孩子
	}
	return;
}

/*前序遍历*/
void ZhongZhui::FrontOrderTraverse(TreeNode* root)
{
	if (root)
	{
		// 操作节点方法，这里只做读取输出用
		if (root->weight != -1)cout << (char)root->data;
		else cout << (int)root->data;
		PreOrderTraverse(root->left);//访问该结点的左孩子
		PreOrderTraverse(root->right);//访问该结点的右孩子
	}
	return;
}

/*返回根节点*/
TreeNode* ZhongZhui::getRoot()
{
	return root;
}

/*计算求职*/
double ZhongZhui::getResult(TreeNode* root)
{
	if (root->left->weight == -1 && root->right->weight == -1)		//左右节点都为数字节点则直接计算
	{
		root->data = calculateStep(root->left->data , root->data, root->right->data );
		root->weight = -1;
		delete root->left;
		delete root->right;
		root->left = NULL;
		root->right = NULL;
		return root->data;
	}
	if (root->left->weight == -1)		//左节点为数字，右节点为操作符，则先计算右子树结果
	{
		return calculateStep(root->left->data , root->data, getResult(root->right));
	}
	else if (root->right->weight == -1)		////右节点为数字，左节点为操作符，则先计算左子树结果
	{
		return calculateStep(getResult(root->left), root->data, root->right->data);
	}
	else {		//左右字数都为操作符，则计算左右子树节点。
		return calculateStep(getResult(root->left), root->data, getResult(root->right));
	}
}

/*单步计算*/
double ZhongZhui::calculateStep(double number1, double op, double number2)
{
	if ((int)op == '+')
	{
		return number1 + number2;
	}
	else if ((int)op == '-')
	{
		return number1 - number2;
	}
	else if ((int)op == '*')
	{
		return number1 * number2;
	}
	else if ((int)op == '/')
	{
		return number1 / number2;
	}
}


