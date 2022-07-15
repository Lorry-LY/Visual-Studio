#include "ZhongZhui.h"

ZhongZhui::ZhongZhui(string str)
{
	int num = 1;			//�������ǰȨ��
	int maxNum = num;		//��������Ȩ��
	int minNum = num;		//�������СȨ��
	for (int i = 0; i < str.length() - 1; i++)
	{
		if ('0' <= str[i] && str[i] <= '9')		//����
		{
			int q = i + 1;
			int numb = 0;
			while ('0' <= str[q] && str[q] <= '9')q++;
			int len = q - i;
			for (int j = 0; j < q - i; j++)
			{
				numb += (str[i + j] - '0') * pow(10, len-1-j);
			}
			i = q - 1;		//�������ֽڵ�
			TreeNode* number = new TreeNode({ 1.0 * numb ,-1,NULL,NULL,NULL});
			numbers.push_back(number);
		}
		else		//�ַ�
		{
			if (str[i] == '(') {		//������������������ȼ�
				if (++num > maxNum) {
					maxNum = num;
				}
			}
			else if (str[i] == ')') {		//�����ż�С��������ȼ�
				if (--num < minNum) {
					minNum = num;
				}
			}
			else {			//����������ڵ�
				TreeNode* option = new TreeNode({ 1.0 * str[i],num,NULL,NULL,NULL });
				options.push_back(option);
			}
		}
	}
	for (int i = maxNum; i >= minNum; i--)		//��������ȼ����������ʼ����ڵ�
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
					else		//������ڵ�ĸ��ڵ㲻Ϊ�գ���Ѱַ������ڵ�
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
					else		//������ڵ�ĸ��ڵ㲻Ϊ�գ���Ѱַ������ڵ�
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

	/*���ڵ����ֵ*/
	TreeNode* temp = numbers[0]->parent;
	while (temp->parent != NULL)
	{
		temp = temp->parent;
	}
	root = temp;
}

/*�������*/
void ZhongZhui::PreOrderTraverse(TreeNode* root)
{
	if (root)
	{
		PreOrderTraverse(root->left);//���ʸý�������
		// �����ڵ㷽��������ֻ����ȡ�����
		if (root->weight != -1)cout << (char)root->data;
		else cout << (int)root->data;
		PreOrderTraverse(root->right);//���ʸý����Һ���
	}
	return;
}

/*ǰ�����*/
void ZhongZhui::FrontOrderTraverse(TreeNode* root)
{
	if (root)
	{
		// �����ڵ㷽��������ֻ����ȡ�����
		if (root->weight != -1)cout << (char)root->data;
		else cout << (int)root->data;
		PreOrderTraverse(root->left);//���ʸý�������
		PreOrderTraverse(root->right);//���ʸý����Һ���
	}
	return;
}

/*���ظ��ڵ�*/
TreeNode* ZhongZhui::getRoot()
{
	return root;
}

/*������ְ*/
double ZhongZhui::getResult(TreeNode* root)
{
	if (root->left->weight == -1 && root->right->weight == -1)		//���ҽڵ㶼Ϊ���ֽڵ���ֱ�Ӽ���
	{
		root->data = calculateStep(root->left->data , root->data, root->right->data );
		root->weight = -1;
		delete root->left;
		delete root->right;
		root->left = NULL;
		root->right = NULL;
		return root->data;
	}
	if (root->left->weight == -1)		//��ڵ�Ϊ���֣��ҽڵ�Ϊ�����������ȼ������������
	{
		return calculateStep(root->left->data , root->data, getResult(root->right));
	}
	else if (root->right->weight == -1)		////�ҽڵ�Ϊ���֣���ڵ�Ϊ�����������ȼ������������
	{
		return calculateStep(getResult(root->left), root->data, root->right->data);
	}
	else {		//����������Ϊ����������������������ڵ㡣
		return calculateStep(getResult(root->left), root->data, getResult(root->right));
	}
}

/*��������*/
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


