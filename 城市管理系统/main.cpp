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
	cout << "欢迎进入民航飞行与地图简易管理系统。" << endl;
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
	cout << "主菜单：" << endl;
	cout << "1、增加城市信息" << endl;
	cout << "2、删除城市信息" << endl;
	cout << "3、修改城市信息" << endl;
	cout << "4、保存城市信息至文件" << endl;
	cout << "5、从文件读取城市信息" << endl;
	cout << "6、显示所有城市信息" << endl;
	cout << "7、设置飞行信息" << endl;
	cout << "8、显示飞机信息" << endl;
	cout << "9、判断起飞飞机是否可以刹车" << endl;
	cout << "10、查询飞机雷达半径内所有城市信息" << endl;
	cout << "0、退出" << endl;
	cout << "请输入选择：";
	int number;
	cin >> number;
	cin.get();
	return number;

}

void appendCity(Map& mapObj)
{
	cout << "请输入增加城市的编号、城市名称、城市x坐标、城市y坐标。" << endl;
	int number, x, y;
	string name;
	cin >> number >> name >> x >> y;
	cin.get();
	mapObj.AddCity(number, name, x, y);
}

void delCity(Map& mapObj)
{
	cout << "请输入删除城市的编号：";
	int num;
	cin >> num;
	cin.get();
	int i = mapObj.FindCity(num);
	if ( i!= -1)
	{
		cout << "确认删除这条记录吗？输入y确认，输入n取消。" << endl;
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
		cout << "该城市不存在。" << endl;
	}
}

void updCity(Map& mapObj)
{
	cout << "请输入修改城市的编号：";
	int num;
	cin >> num;
	cin.get();
	int i = mapObj.FindCity(num);
	if (i != -1)
	{
		mapObj.ShowCity(i);
		cout << "请输入修改城市的名称、城市x坐标、城市y坐标。" << endl;
		int x, y;
		string na;
		cin >> na >> x >> y;
		cin.get();
		mapObj.UpdateCity(i, num, na, x, y);
	}
	else
	{
		cout << "没有找到对应城市。" << endl;
	}
}

void SaveToFile(Map& mapObj)
{
	cout << "请输入保存的文件名和后缀名。" << endl;
	string str;
	cin >> str;
	cin.get();
	mapObj.SavaCity(str);
}

void ReadFroFile(Map& mapObj)
{
	cout << "请输入读取的文件名和后缀名。" << endl;
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
		cout << "没有城市信息。" << endl;
	}
}

void AddPlane(Plane& planeObj)
{
	cout << "请输入飞机的编号，飞机的名称，飞机的x坐标，飞机的y坐标，飞机的重量(t)。" << endl;
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
		cout << "没有飞机信息。" << endl;
	}
	else
		planeObj.show();
}

void Brake(Plane& planeObj)
{
	cout << "请输入飞机的速度(km/h)、剩余跑道的长度(m)。" << endl;
	double sp,dis;
	cin >> sp >> dis;
	cin.get();
	int number = planeObj.GanBrake(sp,dis);
	if (number == -1)
	{
		cout << "没有飞机信息。" << endl;
	}
	else if(number==0)
	{
		cout << "不可以刹车。" << endl;
	}
	else if (number == 1)
	{
		cout << "可以刹车。" << endl;
	}
}

void RadarSearch(Plane& planeObj,Map& mapObj)
{
	cout << "请输入雷达半径：" << endl;
	double radius;
	cin >> radius;
	cin.get();
	planeObj.RadarFind(radius,mapObj);
}

char Quit(Map& mapObj)
{
	cout << "是否要退出，输入y确认，输入n取消。" << endl;
	char ch;
	cin >> ch;
	getchar();
	if (ch == 'y')
	{
		mapObj.SavaCity("database.txt");
	}
	return ch;
}