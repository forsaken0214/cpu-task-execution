#include <Windows.h>
#include<iostream>
#include<string>
//#include<pthread.h>
#include <stdio.h>
#include <io.h>
using namespace std;
HANDLE openEx(LPCSTR dir, LPCSTR aug)
{
	HANDLE aa;
	aa = ShellExecute(
		NULL,												// �����ھ��
		TEXT("open"),											// edit���༭��open���򿪣�print����ӡ��explore�������find������
		dir,			// �ļ�ȫ·�����ļ�����
		aug,												// ��������ʱ�������в���
		NULL,												// Ĭ�ϲ���Ŀ¼Ϊ��ǰĿ¼
		SW_SHOWNORMAL										// ��ʾ��ʽ ����궨��ο���https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-showwindow
	);
	return aa;
}
void closeEx(char name)
{
	system("taskkill /f /im CpuAndMrmory.exe");	
}
int main()
{
	
	/*long listNumber[16] ;
	listNumber[0] = 1155000;
    listNumber[1] = 2405000;
	listNumber[2] = 3705000;
	listNumber[3] = 5270000;
	listNumber[4] = 6825000;
	listNumber[5] = 7855000;
	listNumber[6] = 9585000;
	listNumber[7] = 12085000;
	listNumber[8] = 13685000;
	listNumber[9] = 16485000;
	listNumber[10] = 18885000;
	listNumber[11] = 21885000;
	listNumber[12] = 23885000;
	listNumber[13] = 26885000;
	listNumber[14] = 29885000;
	listNumber[15] = 0;*/

	/*  ShellExecute
		����Ҫʹ�ù���ԱȨ�޴� VS2019 Ҳ���Դ� WinExec ���ܴ򿪵ĳ���
	*/
	//ShellExecute(
	//	NULL,												// �����ھ��
	//	L"open",											// edit���༭��open���򿪣�print����ӡ��explore�������find������
	//	L"C:\\Users\\Administrator\\source\\repos\\CpuAndMrmory\\Debug\\CpuAndMrmory.exe",			// �ļ�ȫ·�����ļ�����
	//	L"1905000",												// ��������ʱ�������в���
	//	NULL,												// Ĭ�ϲ���Ŀ¼Ϊ��ǰĿ¼
	//	SW_SHOWNORMAL										// ��ʾ��ʽ ����궨��ο���https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-showwindow
	//); cout << "ȡɫ�� GetLastError = " << GetLastError() << endl;

	/*ShellExecute(NULL, L"open", L"D:\\MyFiles\\WeGame\\tgp_daemon.exe", NULL, NULL, SW_SHOWNORMAL);
	cout << "tgp_daemon GetLastError = " << GetLastError() << endl;

	ShellExecute(NULL, L"open", L"C:\\Windows\\SysNative\\calc.exe", NULL, NULL, SW_SHOWNORMAL);
	cout << "calc GetLastError = " << GetLastError() << endl;*/
	char aa[22]="\0";
	char bb[22] = "\0";
	
	//system("start D:\\record\\ConsoleApp2.exe");
	for (int n = 0; n < 60;n++) 
	{
		_ltoa_s(n*800000, aa, 10);
		_ltoa_s(n , bb, 10);
	
		openEx("D:\\record1\\mc\\mc.exe", aa);
		openEx("D:\\record1\\CpuAndTemp.exe", bb);
		/*Sleep(180000);*/
		Sleep(286000);
		bool de = true;
		const char* fileName = strcat(bb, ".txt");
		char path[50] = "D:\\record1\\Release\\";
		strcat(path, fileName);
		while (de)
		{
			
			if (!_access(path, 0))
			{
				system("taskkill /f /im mc.exe");
				system("taskkill /f /im CpuAndTemp.exe");
				de = false;
			}			
		}

	}
	

	getchar();
	return 0;
}
