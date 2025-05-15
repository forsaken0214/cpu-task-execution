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
		NULL,												// 父窗口句柄
		TEXT("open"),											// edit：编辑，open：打开，print：打印，explore：浏览，find：搜索
		dir,			// 文件全路径或文件夹名
		aug,												// 程序启动时的命令行参数
		NULL,												// 默认操作目录为当前目录
		SW_SHOWNORMAL										// 显示方式 更多宏定义参考：https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-showwindow
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
		不需要使用管理员权限打开 VS2019 也可以打开 WinExec 不能打开的程序
	*/
	//ShellExecute(
	//	NULL,												// 父窗口句柄
	//	L"open",											// edit：编辑，open：打开，print：打印，explore：浏览，find：搜索
	//	L"C:\\Users\\Administrator\\source\\repos\\CpuAndMrmory\\Debug\\CpuAndMrmory.exe",			// 文件全路径或文件夹名
	//	L"1905000",												// 程序启动时的命令行参数
	//	NULL,												// 默认操作目录为当前目录
	//	SW_SHOWNORMAL										// 显示方式 更多宏定义参考：https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-showwindow
	//); cout << "取色器 GetLastError = " << GetLastError() << endl;

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
