//main.cpp

#include"Editor.h"


int main()
{
	char infName[256], outfName[256];
	cout << "��ӭʹ���ı��༭����"<<endl;
	opens:
	cout << "��������Ҫ��ȡ���ı����֣�";
	cin.getline(infName, 256);
	if (0 == strlen(infName))
	{
		strcpy(infName, "file_in.txt");
	}
	cout << "�����뱣���ļ������֣�";
	cin.getline(outfName, 256);
	if (0 == strlen(outfName))
	{
		strcpy(outfName, "file_out.txt");
	}
	
	try
	{
		Editor text(infName, outfName);
		while (text.GetCommand())
		{
			text.RunCommand();
		}
	}
	catch(string str)
	{
		cout << str << endl;
		if (str == "�ļ���ʧ�ܡ�")
		{
			goto opens;
		}
		
	}
	

	return 0;

}

//int main()
//{
//	const char* str = "i love you";
//	CharString cs(str);
//	CharString ts(cs);
//	cs.Write(cs);
//	cout << endl << cs.Length() << endl;
//	list<char> ls;
//	ls.push_back('i');
//	ls.push_back(' ');
//	ls.push_back('l');
//	ls.push_back('o');
//	ls.push_back('v');
//	ls.push_back('e');
//	CharString es(ls);
//	/*es.Write(es);*/
//	/*cout << cs[2] << endl;
//	cs.Write(cs);
//
//	
//	fstream input("text.txt");
//	if (input.is_open())
//	{
//		cs.Read(input);
//	}
//	input.close();
//	cs.Write(cs);
//	*/
//	/*cs.Concat(cs, ts);
//		cout << endl;
//	cs.Write(cs);*/
//	cs.Copy(cs,ls);
//	cs.Write(cs);
//	
//
//
//	return 0;
//}




