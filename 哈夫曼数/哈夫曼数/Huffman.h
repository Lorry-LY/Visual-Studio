#pragma once


#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct Node
{
	char ch;
	int weight;
	Node* Left;
	Node* Right;

	Node()
	{
		Left = nullptr;
		Right = nullptr;
	}

	Node(int ch,int data)
	{
		Left = nullptr;
		Right = nullptr;
		this->ch = ch;
		weight = data;
	}

	Node(const Node& P)
	{
		ch = P.ch;
		weight = P.weight;
		if (P.Left == nullptr)
		{
			Left = nullptr;
		}
		else
		{
			Left = new Node();
			*Left = *(P.Left);
		}
		if (P.Right == nullptr)
		{
			Right = nullptr;
		}
		else
		{
			Right = new Node();
			*Right = *(P.Right);
		}
	}

	bool operator < (const Node& P) const
	{
		return this->weight > P.weight;
	}
};

class Huffman
{
public:
	Huffman();
	Huffman(const string& sample);
	~Huffman();

	//void MakeEmpty();
	//void DisSt();

	bool IsLeaf(Node* Root);
	void GetFreq(vector<int>&des);
	void BuildTree();
	void BuildCode();
	void GetCodeList();

	void PreOrder();
	void InOrder();

	string Expend(const string &des);
	string Compress(const string &des);
	int GetLength();

private:
	void MakeEmpty(Node* root);
	void BuildCode(Node* root, string str);
	void PreOrder(Node* root);
	void InOrder(Node* root);
	
	unordered_map<char, string>map;
	vector<int> freq;
	vector<char> st;

	Node* Root;

};




