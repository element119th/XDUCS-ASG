#include <stdio.h>
#include <windows.h>
int count1 = 0, count2 = 0;
HANDLE hempty, hproduct, hMutex;

DWORD WINAPI Fun1Proc(LPVOID lpParameter) {        //消费者线程1构造方法
	printf("Consumer thread1 starts!\n");
	while (1) {
		WaitForSingleObject(hMutex, INFINITE); //进入临界区域
		printf("Thread1 gets Mutex!\n");
		WaitForSingleObject(hproduct, INFINITE);
		Sleep(100);
		count1++;
		printf("Consumer thread1 has consumed %d products all together\n", count1);
		ReleaseSemaphore(hempty, 1, NULL);
		ReleaseMutex(hMutex);  //释放互斥量
		printf("Thread1 releases Mutex!\n");
	}

	return 0;
}

DWORD WINAPI Fun2Proc(LPVOID lpParameter) {        //消费者线程2构造方法
	printf("Consumer thread2 starts!\n");
	while (1) {
		WaitForSingleObject(hMutex, INFINITE); //进入临界区域
		WaitForSingleObject(hproduct, INFINITE);
		Sleep(200);
		count2++;
		printf("Consumer thread2 has consumed %d products all together\n", count2);
		ReleaseSemaphore(hempty, 1, NULL);
		ReleaseMutex(hMutex);  //释放互斥量
	}

	return 0;
}

int main() {
	HANDLE hThread1, hThread2;
	hMutex = CreateMutex(NULL, FALSE, NULL);
	hempty = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "empty");   //空闲块信号量
	hproduct = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "product");   //产品数信号量
	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);   //创建消费者线程1
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);   //创建消费者线程2
	WaitForSingleObject(hThread1, INFINITE);  //等待消费者线程1
	WaitForSingleObject(hThread2, INFINITE);  //等待消费者线程1
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	return 1;
}