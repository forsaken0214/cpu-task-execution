#include<stdio.h>
#include<stdlib.h>
# include<string.h>
#include <stdio.h>
#include <pthread.h>
#include   <time.h>
#include <windows.h>

#define NUM_Threads 7
//
#pragma comment(lib, "pthreadVC2.lib")
void Add_Memory(int mn) {
	char* p;
	long b = 1;
	long i = 0;
	long o = 0;
	for (int n = 0;n < mn;n++) {
		p = (char*)malloc(b);
		p[0] = 1;
		//memset(p, 5, sizeof(b)); //����˵��ס�ˣ������Ǳ������Ż��ˣ�ֻ���ϴ�ɱ����

	}
	while (1) {
		/*o = o + 1;*/
	}
}
void add_comp(long count)
{
	int n = 1;
	for (long i = 1;i < count;i++)
	{
		n = n + 1;
		n = n * n;
	}
}
static void usleep(long usec)
{
	HANDLE timer;
	LARGE_INTEGER interval;
	interval.QuadPart = -(10 * usec);

	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &interval, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
}
void* PrintHello(void* arg)
{
	long tmp = *(long*)arg;
	/*printf("Hello,World of Thread in C!\n");*/
   /* return 0;*/
	while (1)
	{
	/*	Add_Memory(300);*/
		add_comp(tmp);
		usleep(145000);
	}
}

int main(int argc, char* argv[])
{
	//long count = strtol(argv[1],NULL,10);
	long count;
	printf("cpu����");
	scanf("%d",&count);
	printf("%d", count);
	int i;
	int ret;
	/*int count = (int)args;*/
	// �����̵߳�id�������������ʹ������
	pthread_t tids[NUM_Threads];
	/*printf("%d", app);*/
	for (i = 0; i < NUM_Threads; i++)
	{
		// ���������ǣ� �������߳�id���̲߳��������õĺ���������ĺ�������
		ret = pthread_create(&tids[i], NULL, PrintHello, (void*)&count);
		usleep(145000);
		if (ret != 0)
		{
			printf("pthread_create error: error_code = \n");
		}
		
	}
	printf("�ڴ����");
	scanf("%d", &count);
	printf("%d", count);
	Add_Memory(count);
	// �ȸ����߳��Ƴ��󣬽��̲Ž���
	pthread_exit(NULL);

	return 0;
}