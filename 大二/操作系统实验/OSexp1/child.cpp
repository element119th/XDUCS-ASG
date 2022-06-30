#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {
	printf("子进程运行!\n");
	Sleep(500);
	char a[20] = {0};
	int num;
	FILE *p;
	if ((p = fopen("1.txt", "w")) == NULL) {         //读入文件，失败报错
		printf("Failed to read file!");
		return 0;
	} else {
		printf("已经创建文件!\n");              //写入文件
		Sleep(500);
		fwrite("XiDian University", 1, strlen("XiDian University"), p);
		fclose(p);
		printf("已经写入数据!\n");
		Sleep(500);
		p = fopen("1.txt", "r");                    //读取文件内容并输出
		num = fread(a, 1, 20, p);
		fclose(p);
		printf("Successfully read %d words:\n", num);
		puts(a);
	}

	Sleep(1000);
	return 1;
}