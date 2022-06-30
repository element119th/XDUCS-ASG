#include <stdio.h>
#include <windows.h>
int count = 0;
HANDLE hempty, hproduct;

DWORD WINAPI ThreadProc(LPVOID lpParameter) {        //生产者线程构造方法
	printf("Create worker thread!\n");
	while (1) {
		WaitForSingleObject(hempty, INFINITE);          //检查空闲块信号量，有空闲块则进行生产
		Sleep(100);
		count++;
		printf("producer has producerd %d products all together\n", count);
		ReleaseSemaphore(hproduct, 1, NULL);   //每次生产一个产品，产品缓冲区中产品数量就加1
	}

	return 0;
}

int main() {
	hempty = CreateSemaphore(NULL, 10, 10, "empty");   //空闲块信号量
	hproduct = CreateSemaphore(NULL, 0, 10, "product");   //产品数信号量
	HANDLE hThread1;
	hThread1 = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);      //创建生产者线程
	WaitForSingleObject(hThread1, INFINITE);    //等待生产者线程结束
	CloseHandle(hThread1);   //关闭句柄

	return 1;
}