#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Windows.h"	//ʹ�ô��ڵĺ�������ͷ�ļ�ΪWIN32ϵͳ�ṩ�ĵײ㺯��
#include "Crsimage.h"  //ң��ͼ������
#define PI       3.14159265358979323846
using namespace std;

//ͼƬ·�� E:\���\design\test.img

// ��Ϊ��Win32ȫ�ֺ�������ʹ��extern "C"
extern "C" HWND WINAPI GetConsoleWindow();
void Usage()
{
	cout << "############ Remote Sensing Image Process Tools.############\n";
	cout << "# X �C Exit Exit\t�˳�����" << endl;
	cout << "# O �C Open \t��Ӱ���ļ�" << endl;
	cout << "# I �C Information\t�����ǰͼ���·�� ������ֵ �������� �������� ������ �͡����з�ʽ����Ϣ" << endl;
	cout << "# C �CClosed\t�رյ�ǰͼ��" << endl;
	cout << "# S �C Statistics\t���ͼ������ͳ���� �����ļ�δ�� �������ʾ" << endl;
	cout << "# H �C Histogram\t���ͼ���ֱ��" << endl;
	cout << "# ? �C Help\t�������Ϣ" << endl;
	cout << "# A �C Save as\t���뱣����ļ�·�� �����ͼ��Ϊ�������ļ�" << endl;
	cout << "# R �C Rotate\tͼ����ת������Ƕ���ʱ��" << endl;
	cout << "# Z �C Zoom\tͼ�����ţ���������߳�" << endl;
	cout << "# F - Filter\t�����˲��ˣ�����˲���ͼ��" << endl;
	cout << "#################################################################" << endl;
}
//��ʾͼ��
void DisplayImage(CRSImage* pRSImg)
{
	if (pRSImg == NULL)   //�����ж�
		return;
	HWND	hwnd = NULL;    //��þ��
	HDC		hdc = NULL;    	// ���ھ��ΪNULL������
	hwnd = GetConsoleWindow();
	if (hwnd == NULL)
		return;     // ����NULL  
	hdc = GetDC(hwnd);
	if (hdc == NULL)
		return;
	int		a, b;
	int		nBands = pRSImg->GetBands();		//����
	int		nSamples = pRSImg->GetSamples();	//��
	int		nLines = pRSImg->GetLines();		//��
	unsigned char*** pppData = pRSImg->GetDataBuffer();	//��ά����ͷָ��
	unsigned char** ppRed = pppData[0];		//��ɫͨ���Ĳ���
	unsigned char** ppGrn = nBands > 2 ? pppData[1] : pppData[0];	//��ɫͨ���Ĳ���
	unsigned char** ppBlu = nBands > 2 ? pppData[2] : pppData[0];	//��ɫͨ���Ĳ���

	// �������أ���ʾͼ��
	for (a = 0; a < nLines; a++)
	{
		for (b = 0; b < nSamples; b++)
		{	//�����Ԫ���
			SetPixel(hdc, b + 350, a, RGB(ppRed[a][b], ppGrn[a][b], ppBlu[a][b]));       //����ͼ��
		}
	}
	ReleaseDC(hwnd, hdc);
}
//�ر�ͼ��
bool CloseImage(CRSImage* pRSImg)
{
	if (pRSImg->FreeBuffer())//�ͷ�ͼ��ռ�ɹ�
	{
		//�����Ļ
		system("cls");
		return true;
	}
	return false;
}
//ͳ����
bool StatisticsImage(CRSImage* pRSImg)
{
	cout << "Basic " << "Stats	  " << "Min	  " << "Max	     " << "Avg	        " << "Vara" << endl;
	int	nBands = pRSImg->GetBands();
	int	nSamples = pRSImg->GetSamples();	//��
	int	nLines = pRSImg->GetLines();		//��
	unsigned char*** pppData = pRSImg->GetDataBuffer();
	for (int i = 0; i < nBands; i++)
	{
		cout << "    Band " << i + 1 << "	  " << pRSImg->BandMin(pppData[i], i) << "	  " << pRSImg->BandMax(pppData[i], i) << "	     " << pRSImg->BandAvg(pppData[i], i) << "	        " << pRSImg->BandVara(pppData[i], i) << endl;
	}
	return true;
}
//ֱ��ͼ
bool HistogramImage(CRSImage* pRSImg)
{
	int	nBands = pRSImg->GetBands();
	int	nSamples = pRSImg->GetSamples();	//��
	int	nLines = pRSImg->GetLines();		//��
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
//д��������ļ�
bool Write(CRSImage* pRSImg, const char* lpstrPath)
{
	int	nBands = pRSImg->GetBands();
	int	nSamples = pRSImg->GetSamples();	//��
	int	nLines = pRSImg->GetLines();		//��
	unsigned char*** pppData = pRSImg->GetDataBuffer();
	ofstream fout(lpstrPath);
	if (fout) { // ��������ɹ�
		FILE* f = fopen(lpstrPath, "wb+");
		for (int i = 0; i < nBands; i++)
		{
			for (int q = 0; q < nLines; q++)
			{
				fwrite(pppData[i][q], sizeof(char), nSamples, f);
			}
		}
		fclose(f); //�ر��ļ�
	}
	return true;
}
//��ʾ��ͼ��
bool displayImage(unsigned char*** new_pppData, int nBands, int nLines, int nSamples)
{
	HWND	hwnd = NULL;//��þ��
	HDC		hdc = NULL;

	// ���ھ��ΪNULL������
	hwnd = GetConsoleWindow();
	if (hwnd == NULL)
		return false;

	// �豸�����ķ���NULL�����򷵻�
	hdc = GetDC(hwnd);
	if (hdc == NULL)
		return false;
	unsigned char** ppRed = new_pppData[0];		//��ɫͨ���Ĳ���
	unsigned char** ppGrn = nBands > 2 ? new_pppData[1] : new_pppData[0];	//��ɫͨ���Ĳ���
	unsigned char** ppBlu = nBands > 2 ? new_pppData[2] : new_pppData[0];	//��ɫͨ���Ĳ���

	// �������أ���ʾͼ��
	for (int n1 = 0; n1 < nLines; n1++)
	{
		for (int n2 = 0; n2 < nSamples; n2++)
		{	//�����Ԫ���
			SetPixel(hdc, n2 + 350, n1, RGB(ppRed[n1][n2], ppGrn[n1][n2], ppBlu[n1][n2]));
		}
	}
	ReleaseDC(hwnd, hdc);
	return {};
}

//ͼ����������ʾ
bool ZoomImage(CRSImage* pRSImg, double zoom)
{
	int	nBands = pRSImg->GetBands();
	int	nLines = pRSImg->GetLines();		//��
	int	nSamples = pRSImg->GetSamples();	//��
	unsigned char*** pppData = pRSImg->GetDataBuffer();
	unsigned char*** new_pppData;

	//��̬������������ڴ�ռ�
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

//ͼ����ת����ʾ
bool RotImage(CRSImage* pRSImg, int rot)
{
	int	nBands = pRSImg->GetBands();
	int	nSamples = pRSImg->GetSamples();	//��
	int	nLines = pRSImg->GetLines();		//��
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

	int newX1 = (int)(oldX1 * cosAn - oldY1 * sinAn + 0.5);       //������С��
	int newY1 = (int)(oldX1 * sinAn + oldY1 * cosAn + 0.5);

	int newX2 = (int)(oldX2 * cosAn - oldY2 * sinAn + 0.5);
	int newY2 = (int)(oldX2 * sinAn + oldY2 * cosAn + 0.5);

	int newX3 = (int)(oldX3 * cosAn - oldY3 * sin(angle) + 0.5);
	int newY3 = (int)(oldX3 * sinAn + oldY3 * cosAn + 0.5);

	int newX4 = (int)(oldX4 * cosAn - oldY4 * sinAn + 0.5);
	int newY4 = (int)(oldX4 * sinAn + oldY4 * cosAn + 0.5);

	int ElWidth = max(abs(newX1 - newX4), abs(newX2 - newX3)) + 1;
	int ElHeight = max(abs(newY1 - newY4), abs(newY2 - newY3)) + 1;

	//��̬������������ڴ�ռ�
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
	char imgPath[50];     //ͼ��·��
	bool openimg;
	bool close;
	CRSImage crsimage;
	do
	{
		cin >> order;
		switch (order)
		{
			// �˴��ص��עswitch-case���﷨
		case 'O':
		case 'o':
			cout << "O �C Open Image" << endl;
			cout << "Please Input Image Path:  " << endl;    //��ʾ����ͼ��·��
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
				cout << "��������" << crsimage.m_Bands << endl;
				cout << "������" << crsimage.m_Lines << endl;
				cout << "������" << crsimage.m_Samples << endl;
				cout << "���з�ʽ��" << crsimage.m_eInterleave << endl;
				cout << "�������ͣ�" << crsimage.m_DataType << endl;
			}
			else
			{
				cout << "�ļ�δ��" << endl;
			}
			Usage();
			break;
		case 'C':
		case 'c':
			cout << "O �C Close Image" << endl;
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
				cout << "�ļ�δ��" << endl;
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
				cout << "�ļ�δ��" << endl;
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
				printf("Please Input File Path:  ");//��ʾ����ͼ��·��
				cin >> imgPath;
				bool success = Write(&crsimage, imgPath);
				if (success)
					cout << "Success" << endl;
				else
					cout << "Fail" << endl;
			}
			else
			{
				cout << "�ļ�δ��" << endl;
			}
			Usage();
			break;
		case 'R':
		case 'r':
			if (openimg)
			{
				printf("��������ʱ����ת�Ƕ�:");
				cin >> rot;
				RotImage(&crsimage, rot);
			}
			else
			{
				cout << "�ļ�δ��" << endl;
			}
			Usage();
			break;
		case 'Z':
		case 'z':
			if (openimg)
			{
				printf("�������ű���:  ");
				cin >> zoom;
				ZoomImage(&crsimage, zoom);
			}
			else
			{
				cout << "�ļ�δ��" << endl;
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
	} while (order != 'x' && order != 'X');	//order=='x'or'X'�����˳�ѭ�����˴��ж�����Ϊfalse��
	// ��!(order=='x' || order=='X') ==> (order!='x' && order!='X')
	return 0;
}
