//main.cpp

#include"Plane.h"

int menu_select();
void appendCity(Map& mapObj);
void updCity(Map& mapObj);
void delCity(Map& mapObj);
void SaveToFile(Map& mapObj);
void ReadFroFile(Map& mapObj);
void ShowAllCities(Map& mapObj);
void AddPlane(Plane& planeObj);
void ShowPlane(Plane& planeObj);
void Brake(Plane& planeObj);
void RadarSearch(Plane& planeObj, Map& mapObj);
char Quit(Map& mapObj);


int main()
{
	Map mapObj;
	Plane planeObj;
	int sel;
	cout << "��ӭ�����񺽷������ͼ���׹���ϵͳ��" << endl;
	for (;;)
	{
		switch (sel=menu_select())
		{
		case 1:appendCity(mapObj);
			break;
		case 2:delCity(mapObj);
			break;
		case 3:updCity(mapObj);
			break;
		case 4:SaveToFile(mapObj);
			break;
		case 5:ReadFroFile(mapObj);
			break;
		case 6:ShowAllCities(mapObj);
			break;
		case 7:AddPlane(planeObj);
			break;
		case 8:ShowPlane(planeObj);
			break;
		case 9:Brake(planeObj);
			break;
		case 10:RadarSearch(planeObj,mapObj);
			break;
		case 0:if (Quit(mapObj) != 'y')
			continue;
			break;
		}
		if (sel ==0)break;
	}

	return 0;
}

int menu_select()
{
	cout << endl;
	cout << "���˵���" << endl;
	cout << "1�����ӳ�����Ϣ" << endl;
	cout << "2��ɾ��������Ϣ" << endl;
	cout << "3���޸ĳ�����Ϣ" << endl;
	cout << "4�����������Ϣ���ļ�" << endl;
	cout << "5�����ļ���ȡ������Ϣ" << endl;
	cout << "6����ʾ���г�����Ϣ" << endl;
	cout << "7�����÷�����Ϣ" << endl;
	cout << "8����ʾ�ɻ���Ϣ" << endl;
	cout << "9���ж���ɷɻ��Ƿ����ɲ��" << endl;
	cout << "10����ѯ�ɻ��״�뾶�����г�����Ϣ" << endl;
	cout << "0���˳�" << endl;
	cout << "������ѡ��";
	int number;
	cin >> number;
	cin.get();
	return number;

}

void appendCity(Map& mapObj)
{
	cout << "���������ӳ��еı�š��������ơ�����x���ꡢ����y���ꡣ" << endl;
	int number, x, y;
	string name;
	cin >> number >> name >> x >> y;
	cin.get();
	mapObj.AddCity(number, name, x, y);
}

void delCity(Map& mapObj)
{
	cout << "������ɾ�����еı�ţ�";
	int num;
	cin >> num;
	cin.get();
	int i = mapObj.FindCity(num);
	if ( i!= -1)
	{
		cout << "ȷ��ɾ��������¼������yȷ�ϣ�����nȡ����" << endl;
		char ch;
		cin >> ch;
		cin.get();
		if (ch == 'y')
		{
			mapObj.DeleteCity(i);
		}
	}
	else
	{
		cout << "�ó��в����ڡ�" << endl;
	}
}

void updCity(Map& mapObj)
{
	cout << "�������޸ĳ��еı�ţ�";
	int num;
	cin >> num;
	cin.get();
	int i = mapObj.FindCity(num);
	if (i != -1)
	{
		mapObj.ShowCity(i);
		cout << "�������޸ĳ��е����ơ�����x���ꡢ����y���ꡣ" << endl;
		int x, y;
		string na;
		cin >> na >> x >> y;
		cin.get();
		mapObj.UpdateCity(i, num, na, x, y);
	}
	else
	{
		cout << "û���ҵ���Ӧ���С�" << endl;
	}
}

void SaveToFile(Map& mapObj)
{
	cout << "�����뱣����ļ����ͺ�׺����" << endl;
	string str;
	cin >> str;
	cin.get();
	mapObj.SavaCity(str);
}

void ReadFroFile(Map& mapObj)
{
	cout << "�������ȡ���ļ����ͺ�׺����" << endl;
	string str;
	cin >> str;
	cin.get();
	mapObj.ReadCity(str);
}

void ShowAllCities(Map& mapObj)
{
	if (mapObj.GetCurCounter())
	{
		mapObj.ShowCities();
	}
	else
	{
		cout << "û�г�����Ϣ��" << endl;
	}
}

void AddPlane(Plane& planeObj)
{
	cout << "������ɻ��ı�ţ��ɻ������ƣ��ɻ���x���꣬�ɻ���y���꣬�ɻ�������(t)��" << endl;
	int num, x, y;
	double w;
	string na;
	cin >> num >> na >> x >> y >> w;
	cin.get();
	planeObj.SetPlane(num, na, w, x, y);
}

void ShowPlane(Plane& planeObj)
{
	if (planeObj.GetNumber() == 2000)
	{
		cout << "û�зɻ���Ϣ��" << endl;
	}
	else
		planeObj.show();
}

void Brake(Plane& planeObj)
{
	cout << "������ɻ����ٶ�(km/h)��ʣ���ܵ��ĳ���(m)��" << endl;
	double sp,dis;
	cin >> sp >> dis;
	cin.get();
	int number = planeObj.GanBrake(sp,dis);
	if (number == -1)
	{
		cout << "û�зɻ���Ϣ��" << endl;
	}
	else if(number==0)
	{
		cout << "������ɲ����" << endl;
	}
	else if (number == 1)
	{
		cout << "����ɲ����" << endl;
	}
}

void RadarSearch(Plane& planeObj,Map& mapObj)
{
	cout << "�������״�뾶��" << endl;
	double radius;
	cin >> radius;
	cin.get();
	planeObj.RadarFind(radius,mapObj);
}

char Quit(Map& mapObj)
{
	cout << "�Ƿ�Ҫ�˳�������yȷ�ϣ�����nȡ����" << endl;
	char ch;
	cin >> ch;
	getchar();
	if (ch == 'y')
	{
		mapObj.SavaCity("database.txt");
	}
	return ch;
}