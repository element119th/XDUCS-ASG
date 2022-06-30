#include <stdio.h>
#include <windows.h>
#include <process.h>

int main() {
	HANDLE p;
	char name[] = {"tql"};
	p = CreateEvent(NULL, false, false, name);
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION pi;
	BOOL b = CreateProcess("C:\\Users\\Administrator\\Desktop\\OSexp3\\child.exe", NULL, NULL, NULL, FALSE,    //创建进程
	                       CREATE_NEW_CONSOLE,
	                       NULL, NULL, &si, &pi);
	if (!b) {                //创建失败报错
		printf("Failed to create process!");
		return 0;
	}
	printf("Wait for event.\n");
	DWORD s;
	s = WaitForSingleObject(p, 5000);         //等待获取信号状态
	if (s == WAIT_TIMEOUT) {                 //等待超时报错
		printf("Failed to wait for the signal!");
		return 1;
	}
	printf("Get the event.\n");          //信号激活
	printf("Press any key to continue.");
	getchar();

	return 0;
}