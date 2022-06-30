#include <stdio.h>
#include <windows.h>
#include <process.h>

int main() {
	char c;
	HANDLE p;
	p = OpenEvent( EVENT_ALL_ACCESS, FALSE, "tql" );          //获取主进程事件句柄
	Sleep(1000);
	printf("Signal the event to Parent?[y\\n]\n");
	scanf("%c", &c);
	if (c == 'y')          //激活信号
		SetEvent(p);
	else                   //设置信号为未激活状态
		ResetEvent(p);
	Sleep(1000);

	return 0;
}