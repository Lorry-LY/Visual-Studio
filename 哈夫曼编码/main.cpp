

#include"BiTreeNode.h"
#include"function.cpp"

int main()
{
	cout << "������Ҫת��Ϊ������������ļ�����";
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
	cout << "������Ҫ����Ϊ������������ļ�����";
	string out_filename;
	cin >> out_filename;
	//getchar();
	if (save(in_filename,out_filename, &b))
	{
		if (transTable(&b))
		{
			cout << "�ļ�����ɹ���" << endl << "ת��Ч��Ϊ��" << Compare(in_filename, out_filename) << endl;
		}
	}
	system("pause");
	return 0;
}