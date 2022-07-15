#include"Huffman.h"
#include<fstream>

int main()
{
	string sample;
	//���ļ�
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
		cout << "�ļ���ʧ�ܡ�" << endl;
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
		cout << "ԭ�ı�Ϊ��" << endl << sample << endl;
		cout << "ת����Ĺ���������Ϊ��" << endl;
		h.GetCodeList();
		cout << "ת��Ч��Ϊ��" << (sample.length() * 8) / (double)h.GetLength();
	}
	catch (string str)
	{
		cout << str << endl;
	}
	

	return 0;
}