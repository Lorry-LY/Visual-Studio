#include "Huffman.h"

int main()
{
	string inputFile, encodeFile, decodeFile;
	cout << "请输入源文件名称：";
	cin >> inputFile;
	cout << "请输入压缩文件名称：";
	cin >> encodeFile;
	cout << "请输入解码文件名称：";
	cin >> decodeFile;
	Huffman f(inputFile);		//创建哈夫曼树
	f.encode();					//哈夫曼编码
	f.saveFile(encodeFile);		//保存编码后文件
	f.decode(decodeFile);		//解码
	f.printEfficiency();		//输出压缩率
	return 0;
}