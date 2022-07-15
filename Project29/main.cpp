#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Windows.h"	//使用窗口的函数，此头文件为WIN32系统提供的底层函数
#include "Crsimage.h"  //遥感图像处理类
#define PI       3.14159265358979323846
using namespace std;

//图片路径 E:\编程\design\test.img

// 因为是Win32全局函数，故使用extern "C"
extern "C" HWND WINAPI GetConsoleWindow();
void Usage()
{
	cout << "############ Remote Sensing Image Process Tools.############\n";
	cout << "# X – Exit Exit\t退出程序" << endl;
	cout << "# O – Open \t打开影像文件" << endl;
	cout << "# I – Information\t输出当前图像的路径 ，行列值 、波段数 、数据类 数据类 型、排列方式等信息" << endl;
	cout << "# C –Closed\t关闭当前图像" << endl;
	cout << "# S – Statistics\t输出图像数据统计量 ，若文件未打开 ，输出提示" << endl;
	cout << "# H – Histogram\t输出图像的直方" << endl;
	cout << "# ? – Help\t输出本信息" << endl;
	cout << "# A – Save as\t输入保存的文件路径 ，输出图像为二进制文件" << endl;
	cout << "# R – Rotate\t图像旋转，输入角度逆时针" << endl;
	cout << "# Z – Zoom\t图像缩放，输入比例尺出" << endl;
	cout << "# F - Filter\t输入滤波核，输出滤波后图像" << endl;
	cout << "#################################################################" << endl;
}
//显示图像
void DisplayImage(CRSImage* pRSImg)
{
	if (pRSImg == NULL)   //参数判断
		return;
	HWND	hwnd = NULL;    //获得句柄
	HDC		hdc = NULL;    	// 窗口句柄为NULL，返回
	hwnd = GetConsoleWindow();
	if (hwnd == NULL)
		return;     // 返回NULL  
	hdc = GetDC(hwnd);
	if (hdc == NULL)
		return;
	int		a, b;
	int		nBands = pRSImg->GetBands();		//波段
	int		nSamples = pRSImg->GetSamples();	//列
	int		nLines = pRSImg->GetLines();		//行
	unsigned char*** pppData = pRSImg->GetDataBuffer();	//三维数组头指针
	unsigned char** ppRed = pppData[0];		//红色通道的波段
	unsigned char** ppGrn = nBands > 2 ? pppData[1] : pppData[0];	//绿色通道的波段
	unsigned char** ppBlu = nBands > 2 ? pppData[2] : pppData[0];	//蓝色通道的波段

	// 遍历像素，显示图像
	for (a = 0; a < nLines; a++)
	{
		for (b = 0; b < nSamples; b++)
		{	//逐个像元输出
			SetPixel(hdc, b + 350, a, RGB(ppRed[a][b], ppGrn[a][b], ppBlu[a][b]));       //右移图像
		}
	}
	ReleaseDC(hwnd, hdc);
}
//关闭图像
bool CloseImage(CRSImage* pRSImg)
{
	if (pRSImg->FreeBuffer())//释放图像空间成功
	{
		//清除屏幕
		system("cls");
		return true;
	}
	return false;
}
//统计量
bool StatisticsImage(CRSImage* pRSImg)
{
	cout << "Basic " << "Stats	  " << "Min	  " << "Max	     " << "Avg	        " << "Vara" << endl;
	int	nBands = pRSImg->GetBands();
	int	nSamples = pRSImg->GetSamples();	//列
	int	nLines = pRSImg->GetLines();		//行
	unsigned char*** pppData = pRSImg->GetDataBuffer();
	for (int i = 0; i < nBands; i++)
	{
		cout << "    Band " << i + 1 << "	  " << pRSImg->BandMin(pppData[i], i) << "	  " << pRSImg->BandMax(pppData[i], i) << "	     " << pRSImg->BandAvg(pppData[i], i) << "	        " << pRSImg->BandVara(pppData[i], i) << endl;
	}
	return true;
}
//直方图
bool HistogramImage(CRSImage* pRSImg)
{
	int	nBands = pRSImg->GetBands();
	int	nSamples = pRSImg->GetSamples();	//列
	int	nLines = pRSImg->GetLines();		//行
	unsigned char*** pppData = pRSImg->GetDataBuffer();
	double point = nSamples * nLines;
	for (int i = 0; i < nBands; i++)
	{
		cout << "Histogram" << setw(4) << "DN" << setw(6) << "counts" << setw(5) << "n" << setw(2) << "Percent" << setw(7) << "Acc Pct  " << endl;
		int n = 0;
		for (int j = 0; j < 101; j++)
		{
			int counts = pRSImg->BandDN(pppData[i], i, j);
			n += counts;
			double percent = counts / point;
			double accpct = n / point;
			cout << setw(4) << "Band " << i + 1 << setw(5) << j << setw(6) << counts << setw(6) << n << setw(10) << std::fixed << percent << setw(9) << std::fixed << accpct << endl;
		}
	}
	return  true;
}
//写入二进制文件
bool Write(CRSImage* pRSImg, const char* lpstrPath)
{
	int	nBands = pRSImg->GetBands();
	int	nSamples = pRSImg->GetSamples();	//列
	int	nLines = pRSImg->GetLines();		//行
	unsigned char*** pppData = pRSImg->GetDataBuffer();
	ofstream fout(lpstrPath);
	if (fout) { // 如果创建成功
		FILE* f = fopen(lpstrPath, "wb+");
		for (int i = 0; i < nBands; i++)
		{
			for (int q = 0; q < nLines; q++)
			{
				fwrite(pppData[i][q], sizeof(char), nSamples, f);
			}
		}
		fclose(f); //关闭文件
	}
	return true;
}
//显示新图像
bool displayImage(unsigned char*** new_pppData, int nBands, int nLines, int nSamples)
{
	HWND	hwnd = NULL;//获得句柄
	HDC		hdc = NULL;

	// 窗口句柄为NULL，返回
	hwnd = GetConsoleWindow();
	if (hwnd == NULL)
		return false;

	// 设备上下文返回NULL，程序返回
	hdc = GetDC(hwnd);
	if (hdc == NULL)
		return false;
	unsigned char** ppRed = new_pppData[0];		//红色通道的波段
	unsigned char** ppGrn = nBands > 2 ? new_pppData[1] : new_pppData[0];	//绿色通道的波段
	unsigned char** ppBlu = nBands > 2 ? new_pppData[2] : new_pppData[0];	//蓝色通道的波段

	// 遍历像素，显示图像
	for (int n1 = 0; n1 < nLines; n1++)
	{
		for (int n2 = 0; n2 < nSamples; n2++)
		{	//逐个像元输出
			SetPixel(hdc, n2 + 350, n1, RGB(ppRed[n1][n2], ppGrn[n1][n2], ppBlu[n1][n2]));
		}
	}
	ReleaseDC(hwnd, hdc);
	return {};
}

//图像缩放与显示
bool ZoomImage(CRSImage* pRSImg, double zoom)
{
	int	nBands = pRSImg->GetBands();
	int	nLines = pRSImg->GetLines();		//行
	int	nSamples = pRSImg->GetSamples();	//列
	unsigned char*** pppData = pRSImg->GetDataBuffer();
	unsigned char*** new_pppData;

	//动态申请新数组的内存空间
	new_pppData = (unsigned char***)malloc(nBands * sizeof(char**));
	for (int i = 0; i < nBands; i++)
	{
		new_pppData[i] = (unsigned char**)malloc(round(nLines * zoom) * sizeof(char*));
		for (int q = 0; q < round(nLines * zoom); q++)
		{
			new_pppData[i][q] = (unsigned char*)malloc(round(nSamples * zoom) * sizeof(char));
		}
	}
	for (int x = 0; x < nBands; x++)
	{
		for (int y = 0; y < round(nLines * zoom); y++)
		{
			for (int z = 0; z < round(nSamples * zoom); z++)
			{
				int a = round(y * 1 / zoom);
				int b = round(z * 1 / zoom);
				new_pppData[x][y][z] = pppData[x][a][b];
			}
		}
	}
	system("cls");
	Usage();
	displayImage(new_pppData, nBands, round(nLines * zoom), round(nSamples * zoom));
	return true;
}

//图像旋转与显示
bool RotImage(CRSImage* pRSImg, int rot)
{
	int	nBands = pRSImg->GetBands();
	int	nSamples = pRSImg->GetSamples();	//列
	int	nLines = pRSImg->GetLines();		//行
	unsigned char*** pppData = pRSImg->GetDataBuffer();
	unsigned char*** new_pppData;
	double angle = -rot / 180.0f * PI;
	int height = nLines;
	int width = nSamples;

	int oldX1 = -width / 2;
	int oldY1 = height / 2;
	int oldX2 = width / 2;
	int oldY2 = height / 2;
	int oldX3 = -width / 2;
	int oldY3 = -height / 2;
	int oldX4 = width / 2;
	int oldY4 = -height / 2;
	double cosAn = std::cos(angle);
	double sinAn = std::sin(angle);

	int newX1 = (int)(oldX1 * cosAn - oldY1 * sinAn + 0.5);       //不能有小数
	int newY1 = (int)(oldX1 * sinAn + oldY1 * cosAn + 0.5);

	int newX2 = (int)(oldX2 * cosAn - oldY2 * sinAn + 0.5);
	int newY2 = (int)(oldX2 * sinAn + oldY2 * cosAn + 0.5);

	int newX3 = (int)(oldX3 * cosAn - oldY3 * sin(angle) + 0.5);
	int newY3 = (int)(oldX3 * sinAn + oldY3 * cosAn + 0.5);

	int newX4 = (int)(oldX4 * cosAn - oldY4 * sinAn + 0.5);
	int newY4 = (int)(oldX4 * sinAn + oldY4 * cosAn + 0.5);

	int ElWidth = max(abs(newX1 - newX4), abs(newX2 - newX3)) + 1;
	int ElHeight = max(abs(newY1 - newY4), abs(newY2 - newY3)) + 1;

	//动态申请新数组的内存空间
	new_pppData = (unsigned char***)malloc(nBands * sizeof(char**));
	for (int i = 0; i < nBands; i++)
	{
		new_pppData[i] = (unsigned char**)malloc(ElHeight * sizeof(char*));
		for (int q = 0; q < ElHeight; q++)
		{
			new_pppData[i][q] = (unsigned char*)malloc(ElWidth * sizeof(char));
		}
	}
	for (int m = 0; m < nBands; m++)
	{
		int N_x = 0;
		int N_y = 0;
		for (int i = 0; i < ElWidth; i++)
		{
			for (int j = 0; j < ElHeight; j++)
			{
				N_x = round(double(i - ElWidth / 2.0f) * cosAn + double(j - ElHeight / 2.0f) * sinAn + width / 2.0f);
				N_y = round(-double(i - ElWidth / 2.0f) * sinAn + double(j - ElHeight / 2.0f) * cosAn + height / 2.0f);
				if (N_x < 0 || N_x >= width || N_y < 0 || N_y >= height)
				{
					new_pppData[m][j][i] = 0;
				}
				else
				{
					new_pppData[m][j][i] = pppData[m][N_y][N_x];
				}
			}
		}
	}
	system("cls");
	Usage();
	displayImage(new_pppData, nBands, ElHeight, ElWidth);
	return true;
}
int main()
{
	Usage();
	char order;
	double zoom;
	int rot;
	char imgPath[50];     //图像路径
	bool openimg;
	bool close;
	CRSImage crsimage;
	do
	{
		cin >> order;
		switch (order)
		{
			// 此处重点关注switch-case的语法
		case 'O':
		case 'o':
			cout << "O – Open Image" << endl;
			cout << "Please Input Image Path:  " << endl;    //提示输入图像路径
			cin >> imgPath;
			openimg = crsimage.Open(imgPath);
			Usage();
			if (openimg)
				DisplayImage(&crsimage);
			break;
		case 'I':
		case 'i':
			if (openimg)
			{
				cout << "波段数：" << crsimage.m_Bands << endl;
				cout << "行数：" << crsimage.m_Lines << endl;
				cout << "列数：" << crsimage.m_Samples << endl;
				cout << "排列方式：" << crsimage.m_eInterleave << endl;
				cout << "数据类型：" << crsimage.m_DataType << endl;
			}
			else
			{
				cout << "文件未打开" << endl;
			}
			Usage();
			break;
		case 'C':
		case 'c':
			cout << "O – Close Image" << endl;
			close = CloseImage(&crsimage);
			Usage();
			if (close)
			{
				openimg = false;
				Usage();
				cout << "Close Success!" << endl;
			}
			break;
		case 'S':
		case 's':
			if (openimg)
			{
				StatisticsImage(&crsimage);
			}
			else
			{
				cout << "文件未打开" << endl;
			}
			Usage();
			break;
		case 'H':
		case 'h':
			if (openimg)
			{
				HistogramImage(&crsimage);
			}
			else
			{
				cout << "文件未打开" << endl;
			}
			Usage();
			break;
		case '?':
			Usage();
			break;
		case 'A':
		case 'a':
			if (openimg)
			{
				printf("Please Input File Path:  ");//提示输入图像路径
				cin >> imgPath;
				bool success = Write(&crsimage, imgPath);
				if (success)
					cout << "Success" << endl;
				else
					cout << "Fail" << endl;
			}
			else
			{
				cout << "文件未打开" << endl;
			}
			Usage();
			break;
		case 'R':
		case 'r':
			if (openimg)
			{
				printf("请输入逆时针旋转角度:");
				cin >> rot;
				RotImage(&crsimage, rot);
			}
			else
			{
				cout << "文件未打开" << endl;
			}
			Usage();
			break;
		case 'Z':
		case 'z':
			if (openimg)
			{
				printf("输入缩放比例:  ");
				cin >> zoom;
				ZoomImage(&crsimage, zoom);
			}
			else
			{
				cout << "文件未打开" << endl;
			}
			Usage();
			break;
		case 'X':
		case 'x':
			cout << "Menu Exit." << endl;
			break;
		default:
			cout << "Menu Empty." << endl;
			break;
		}
		// switch - case end
	} while (order != 'x' && order != 'X');	//order=='x'or'X'，则退出循环，此处判断条件为false，
	// 即!(order=='x' || order=='X') ==> (order!='x' && order!='X')
	return 0;
}
