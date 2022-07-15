#include "Huffman.h"
#include <algorithm>

Huffman::Huffman()
{
	root = new Node();
}

Huffman::Huffman(string filename)		//构造函数
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

Node* Huffman::createTree(vector<Node*> nodes)		//建树
{
	if (nodes.empty()) {		//空文件
		return new Node();
	}
	if (nodes.size() == 1) {	//只有一个字符的文件
		return nodes[0];
	}
	while (nodes.size() != 1)
	{
		/*取出降序排序向量后两个节点*/
		Node* node1 = nodes.back();
		nodes.pop_back();
		Node* node2 = nodes.back();
		nodes.pop_back();
		/*构造两节点父节点*/
		Node* newNode = new Node({ -1,node1->weight + node2->weight,NULL,node1,node2 });
		node1->parent = newNode;
		node2->parent = newNode;
		//把父节点插入排序到向量里
		insertSort(nodes, newNode);
	}
	return nodes[0];
}

vector<Node*> Huffman::getVector(string str)
{
	vector<Node*> nodes;			//字符向量
	int letters[256] = { 0 };		//字符数数组
	for (int i = 0; i < str.size() - 1; i++)
	{
		//统计各个字符出现次数
		letters[str[i]]++;
	}
	for (int i = 0; i < 256; i++)
	{
		/*对出现过的字符构造节点压入向量*/
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
	/*降序排序向量*/
	sort(nodes.begin(), nodes.end(), cmp);
	return nodes;
}

void Huffman::insertSort(vector<Node*>& nodes, Node* newNode)		//插入排序
{
	if (nodes.empty()) {			//空向量直接插入
		nodes.push_back(newNode);
		return;
	}
	if (nodes.size() == 1) {		//一个节点的向量判断插入前面或者后面
		if (cmp(nodes[0], newNode))nodes.push_back(newNode);
		else {
			Node* oldNode = nodes.back();
			nodes.pop_back();
			nodes.push_back(newNode);
			nodes.push_back(oldNode);
		}
		return;
	}
	if (cmp(newNode, nodes[0])) {		//新节点权重大于头节点
		nodes.insert(nodes.begin(), newNode);
		return;
	}
	for (vector<Node*>::iterator it = nodes.begin(); it < nodes.end(); )		//新节点权重位于中间
	{
		if (cmpEqual(*it++, newNode) && cmpEqual(newNode, *it)) {
			nodes.insert(it, newNode);
			return;
		}
	}
	//新节点权重最小
	nodes.push_back(newNode);

}

void Huffman::encode()		//编码
{
	ofstream file("encodeTable.txt", ios::trunc);
	if (file) {
		post_order(root, file);		//后序遍历
	}
	file.close();
}

void Huffman::saveFile(string filename)		//保存压缩文件
{
	ifstream inFile(inputFile);
	ofstream outFile(filename, ios::trunc);
	if (inFile && outFile)
	{
		outputFile = filename;
		while (!inFile.eof())
		{
			char ch = inFile.get();
			if (ch != -1) {			//参照编码表写入文件
				outFile << encodeTable[ch];
			}
		}
		inFile.close();
		outFile.close();
	}
}

void Huffman::decode(string filename)		//解码
{
	ifstream outFile(outputFile);
	ofstream decodeFile(filename, ios::trunc);
	if (outFile && decodeFile)
	{
		string str;
		while (!outFile.eof())
		{
			char ch = outFile.get();
			str += ch;			//每次多读一个字符
			map<string, char>::iterator it = decodeTable.find(str);		//对比解码表是否匹配
			if (it != decodeTable.end()) {		//匹配到字符
				decodeFile << (*it).second;
				str = "";
			}
		}
	}
}

void Huffman::post_order(Node* root, ofstream& file)			//后序遍历
{
	if (root)
	{
		post_order(root->leftChild, file);
		post_order(root->rightChild, file);
		if (root->value != -1) {
			int length = 0;
			string str = "";
			Node* temp = root;
			/*向上查找根节点获取编码值*/
			while (temp->parent != NULL)
			{
				if (temp->parent->leftChild == temp) {
					str = "0" + str;
				}
				else {
					str = '1' + str;
				}
				length++;		//编码文件长度++
				temp = temp->parent;
			}
			outputFileLength += length * root->weight;
			encodeTable[(char)root->value] = str;		//构造编码表
			decodeTable[str] = (char)root->value;		//构造解码表
			file << (char)root->value << " " << root->weight << " " << str << endl;		//构造编码文件（encode.txt）
		}
	}
}

void Huffman::printEfficiency()			//打印效率
{
	cout << "源文件大小为：" << inputFileLength << "     " << "哈夫曼编码文件长度为：" << outputFileLength << "    " << "压缩率为：";
	printf("%.2f\n", 1.0 * inputFileLength / outputFileLength);
}
