#include "Huffman.h"
#include <algorithm>

Huffman::Huffman()
{
	root = new Node();
}

Huffman::Huffman(string filename)		//���캯��
{
	ifstream file(filename);
	if (file) {
		inputFile = filename;
		string str;
		while (!file.eof())
		{
			char ch = file.get();
			str += ch;
		}
		file.close();
		inputFileLength = 8 * (str.size() - 1);
		root = createTree(getVector(str));

	}
}

Node* Huffman::createTree(vector<Node*> nodes)		//����
{
	if (nodes.empty()) {		//���ļ�
		return new Node();
	}
	if (nodes.size() == 1) {	//ֻ��һ���ַ����ļ�
		return nodes[0];
	}
	while (nodes.size() != 1)
	{
		/*ȡ���������������������ڵ�*/
		Node* node1 = nodes.back();
		nodes.pop_back();
		Node* node2 = nodes.back();
		nodes.pop_back();
		/*�������ڵ㸸�ڵ�*/
		Node* newNode = new Node({ -1,node1->weight + node2->weight,NULL,node1,node2 });
		node1->parent = newNode;
		node2->parent = newNode;
		//�Ѹ��ڵ��������������
		insertSort(nodes, newNode);
	}
	return nodes[0];
}

vector<Node*> Huffman::getVector(string str)
{
	vector<Node*> nodes;			//�ַ�����
	int letters[256] = { 0 };		//�ַ�������
	for (int i = 0; i < str.size() - 1; i++)
	{
		//ͳ�Ƹ����ַ����ִ���
		letters[str[i]]++;
	}
	for (int i = 0; i < 256; i++)
	{
		/*�Գ��ֹ����ַ�����ڵ�ѹ������*/
		if (letters[i] != 0)
		{
			Node* temp = new Node();
			temp->value = i;
			temp->weight = letters[i];
			temp->parent = NULL;
			temp->leftChild = NULL;
			temp->rightChild = NULL;
			nodes.push_back(temp);
		}
	}
	/*������������*/
	sort(nodes.begin(), nodes.end(), cmp);
	return nodes;
}

void Huffman::insertSort(vector<Node*>& nodes, Node* newNode)		//��������
{
	if (nodes.empty()) {			//������ֱ�Ӳ���
		nodes.push_back(newNode);
		return;
	}
	if (nodes.size() == 1) {		//һ���ڵ�������жϲ���ǰ����ߺ���
		if (cmp(nodes[0], newNode))nodes.push_back(newNode);
		else {
			Node* oldNode = nodes.back();
			nodes.pop_back();
			nodes.push_back(newNode);
			nodes.push_back(oldNode);
		}
		return;
	}
	if (cmp(newNode, nodes[0])) {		//�½ڵ�Ȩ�ش���ͷ�ڵ�
		nodes.insert(nodes.begin(), newNode);
		return;
	}
	for (vector<Node*>::iterator it = nodes.begin(); it < nodes.end(); )		//�½ڵ�Ȩ��λ���м�
	{
		if (cmpEqual(*it++, newNode) && cmpEqual(newNode, *it)) {
			nodes.insert(it, newNode);
			return;
		}
	}
	//�½ڵ�Ȩ����С
	nodes.push_back(newNode);

}

void Huffman::encode()		//����
{
	ofstream file("encodeTable.txt", ios::trunc);
	if (file) {
		post_order(root, file);		//�������
	}
	file.close();
}

void Huffman::saveFile(string filename)		//����ѹ���ļ�
{
	ifstream inFile(inputFile);
	ofstream outFile(filename, ios::trunc);
	if (inFile && outFile)
	{
		outputFile = filename;
		while (!inFile.eof())
		{
			char ch = inFile.get();
			if (ch != -1) {			//���ձ����д���ļ�
				outFile << encodeTable[ch];
			}
		}
		inFile.close();
		outFile.close();
	}
}

void Huffman::decode(string filename)		//����
{
	ifstream outFile(outputFile);
	ofstream decodeFile(filename, ios::trunc);
	if (outFile && decodeFile)
	{
		string str;
		while (!outFile.eof())
		{
			char ch = outFile.get();
			str += ch;			//ÿ�ζ��һ���ַ�
			map<string, char>::iterator it = decodeTable.find(str);		//�ԱȽ�����Ƿ�ƥ��
			if (it != decodeTable.end()) {		//ƥ�䵽�ַ�
				decodeFile << (*it).second;
				str = "";
			}
		}
	}
}

void Huffman::post_order(Node* root, ofstream& file)			//�������
{
	if (root)
	{
		post_order(root->leftChild, file);
		post_order(root->rightChild, file);
		if (root->value != -1) {
			int length = 0;
			string str = "";
			Node* temp = root;
			/*���ϲ��Ҹ��ڵ��ȡ����ֵ*/
			while (temp->parent != NULL)
			{
				if (temp->parent->leftChild == temp) {
					str = "0" + str;
				}
				else {
					str = '1' + str;
				}
				length++;		//�����ļ�����++
				temp = temp->parent;
			}
			outputFileLength += length * root->weight;
			encodeTable[(char)root->value] = str;		//��������
			decodeTable[str] = (char)root->value;		//��������
			file << (char)root->value << " " << root->weight << " " << str << endl;		//��������ļ���encode.txt��
		}
	}
}

void Huffman::printEfficiency()			//��ӡЧ��
{
	cout << "Դ�ļ���СΪ��" << inputFileLength << "     " << "�����������ļ�����Ϊ��" << outputFileLength << "    " << "ѹ����Ϊ��";
	printf("%.2f\n", 1.0 * inputFileLength / outputFileLength);
}
