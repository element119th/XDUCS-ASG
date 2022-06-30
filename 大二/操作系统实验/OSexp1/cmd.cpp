#include <stdio.h>
#include <windows.h>

int main() {
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION pi;
	BOOL b = CreateProcess("C:\\Users\\Administrator\\Desktop\\OSexp\\child.exe", NULL, NULL, NULL, FALSE,    //创建进程
	                       CREATE_NEW_CONSOLE,
	                       NULL, NULL, &si, &pi);
	if (!b) {                //创建失败报错
		printf("Failed to create process!");
		return 0;
	} else {
		int i, sum = 0;
		char a[20] = {0};
		FILE *p;
		for (i = 1; i <= 100; i++) {              //执行计算
			sum += i;
			printf("sum = %d\n", sum);
			Sleep(10);
		}
		WaitForSingleObject(pi.hProcess, INFINITE);        //等待子进程执行
		p = fopen("1.txt", "r");                  //读入子进程文件并输出
		int num = fread(a, 1, 20, p);
		fclose(p);
		printf("Successfully read %d words:\n", num);
		puts(a);
		Sleep(500);
		printf("子进程结束");
	}

	return 0;
}