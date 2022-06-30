#include<stdio.h>
#include<string.h>

void sort(char a[],char b[],char c[],int a1,int a2,int b1,int b2,int c0) {
	int i,t = 0,j;
	if(c0 == -1) return;
	c[c0] = a[a1];
	if(b1 == b2) t = 1;
	j = b1;
	for(i = b1;i <= b2;i++) {
		if(b[i] == c[c0]) {
			b1 = i+1;
			break;
		}
	}  
	if(b1 <= b2 && t == 0) sort(a,b,c,b1 + a2 - b2,a2,b1,b2,c0-1);
	if(i >= 1 && t == 0) sort(a,b,c,a1+1,i-j+a1,j,i-1,c0-b2+b1-2);
}

int main() {
	char a[100],b[100],c[100];
	gets(a);
	gets(b);
	sort(a,b,c,0,strlen(a) - 1,0,strlen(b) - 1,strlen(b) - 1);
	puts(c);
	
	return 0;
}
