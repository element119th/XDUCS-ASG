#include <stdio.h>
#include <windows.h>

static int count = 10;
DWORD WINAPI ThreadProc(LPVOID lpParameter) {        //线程构造方法
	printf("新线程运行!\n");
	for (count = 1; count <= 5; count++) {
		printf("线程count = %d\n", count);
	}
	printf("线程等待五秒钟\n");
	Sleep(5000);
	printf("新线程结束!\n");

	return 0;
}

int main() {
	printf("进程运行!\n进程count = %d\n", count);
	HANDLE pthread;
	pthread = CreateThread( NULL, 0, ThreadProc, NULL, 0, NULL); //创建线程
	WaitForSingleObject(pthread, INFINITE);        //等待线程执行
	printf("进程结束");

	return 0;
}
