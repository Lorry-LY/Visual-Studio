

#include"BiTreeNode.h"
#include"function.cpp"

int main()
{
	cout << "请输入要转换为哈夫曼编码的文件名：";
	string in_filename;
	cin >> in_filename;
	getchar();
	int charNumber[29] = { 0 };
	if (!init(in_filename, charNumber))
	{
		system("pause"); return 0;
	}
	BinaryTree b(charNumber,29);
	//cout << b.getHuffmanCode('a');
	cout << "请输入要保存为哈夫曼编码的文件名：";
	string out_filename;
	cin >> out_filename;
	//getchar();
	if (save(in_filename,out_filename, &b))
	{
		if (transTable(&b))
		{
			cout << "文件保存成功。" << endl << "转化效率为：" << Compare(in_filename, out_filename) << endl;
		}
	}
	system("pause");
	return 0;
}