#include "Huffman.h"


Huffman::Huffman(const string &sample)
{
	int len = sample.length();
	try {	
		if (0 == len)
		{
			throw "ÎÄ¼þÎª¿Õ¡£";
		}
	}
	catch (string)
	{
		throw;
	}
	
	
	unordered_map<char, int>mymap;
	for (int i = 0; i < len; i++)
	{
		if (mymap.find(sample[i]) == mymap.end())
		{
			mymap[sample[i]] = 1;
		}
		else
		{
			mymap[sample[i]] ++;
		}
	}
	for (const auto& pair : mymap)
	{
		st.push_back(pair.first);
		freq.push_back(pair.second);
	}
}

Huffman::~Huffman()
{
	MakeEmpty(Root);
}

bool Huffman::IsLeaf(Node* root)
{
	if (nullptr == root)return false;
	if (root->Left == nullptr && root->Right == nullptr)
		return true;
	else return false;
}

void Huffman::GetFreq(vector<int>& des)
{
	for (int i = 0; i < freq.size(); i++)
	{
		des.push_back(freq[i]);
	}
}

void Huffman::BuildTree()
{
	priority_queue<Node>myqueue;
	for (int i = 0; i < freq.size(); i++)
	{
		Node* temp = new Node(st[i],freq[i]);
		myqueue.push(*temp);
	}

	while (myqueue.size() > 1)
	{
		Node left = myqueue.top();
		myqueue.pop();
		Node right = myqueue.top();
		myqueue.pop();

		Node* parent = new Node(-1,left.weight + right.weight);
		parent->ch = -1;
		parent->Left = &left;
		parent->Right = &right;
		myqueue.push(*parent);
	}
	
	Root = new Node();
	*Root = myqueue.top();
	myqueue.pop();
}

void Huffman::BuildCode()
{
	if (Root == nullptr)return;
	string temp;
	temp.clear();
	BuildCode(Root, temp);
}

void Huffman::PreOrder()
{
	if (Root == nullptr)return;
	PreOrder(Root);
}

void Huffman::InOrder()
{
	if (Root == nullptr)return;
	InOrder(Root);
}

string Huffman::Expend(const string& des)
{
	string res;
	int i = 0, n = des.size();
	Node* temp = new Node();
	temp = Root;
	while (i < n)
	{
		if ('0' == des[i])
		{
			temp = temp->Left;
			i++;
			if (IsLeaf(temp))
			{
				res += st[temp->ch];
				temp = Root;
				continue;
			}
		}
		if (des[i] == '1')
		{
			temp = temp->Right;
			i++;
			if (IsLeaf(temp))
			{
				res += st[temp->ch];
				temp = Root;
				continue;
			}
		}
	}
	return res;
}

string Huffman::Compress(const string& des)
{
	string res;
	for (int i = 0; i < des.length(); i++)
	{
		if (des[i] == '\n' || des[i] == ' ')
		{
			continue;
		}
		res += map[des[i]];
	}
	return res;
}

void Huffman::PreOrder(Node* root)
{
	if (root == nullptr)return;
	if (root->ch == -1)
	{
		cout << "?" << " : " << root->weight << " ";
	}
	else
	cout << (char)root->ch << " : " << root->weight << " ";
	PreOrder(root->Left);
	PreOrder(root->Right);
}

void Huffman::InOrder(Node* root)
{
	if (root == nullptr)return;
	InOrder(root->Left);
	if(root->ch==-1)
	cout << "?" << " : " << root->weight << " ";
	else
	cout << (char)root->ch << " : " << root->weight << " ";
	InOrder(root->Right);
}

void Huffman::MakeEmpty(Node* root)
{
	if (root == nullptr)return;
	if (root->Left)MakeEmpty(root->Left);
	if (root->Right)MakeEmpty(root->Right);
	//delete root;
}

void Huffman::BuildCode(Node* root, string str)
{
	if (IsLeaf(root) && root->ch >= 0)
	{
		map[root->ch] = str;
		return;
	}
	if (root->Left)BuildCode(root->Left, str + '0');
	if (root->Right)BuildCode(root->Right, str + '1');
}

void Huffman::GetCodeList()
{
	for (int i = 0; i < st.size(); i++)
	{
		cout << st[i] << " : " << map[st[i]] << endl;
	}
}

int Huffman::GetLength()
{
	int len = 0;
	for (int i = 0; i < st.size(); i++)
	{
		len += freq[i] * map[st[i]].length();
	}
	return len;
}


