#include"Huffman.h"
#include<fstream>

int main()
{
	string sample;
	//读文件
	fstream file("text.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			int temp=file.get();
			sample += temp;
		}
		file.close();
	}
	else
	{
		cout << "文件打开失败。" << endl;
		return 1;
	}
	try {
		Huffman h(sample);
		vector<int>des;
		h.GetFreq(des);
		h.BuildTree();
		/*h.PreOrder();
		cout << endl << endl;
		h.InOrder();*/
		h.BuildCode();
		cout << "原文本为：" << endl << sample << endl;
		cout << "转化后的哈夫曼编码为：" << endl;
		h.GetCodeList();
		cout << "转化效率为：" << (sample.length() * 8) / (double)h.GetLength();
	}
	catch (string str)
	{
		cout << str << endl;
	}
	

	return 0;
}