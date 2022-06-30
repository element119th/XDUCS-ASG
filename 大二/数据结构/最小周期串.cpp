#include<stdio.h>
#include<string.h>

int find(char a[],int t,int n) {
    if(n % t != 0) return 0;
	int b[t],i,j;
	for(i = 0;i < t;i++) b[i] = a[i];	
	for(i = t;i < n;i+=t) {
		for(j = 0;j <t;j++) if(b[j] != a[i+j]) return 0;
	}
	
	return 1;
}

int main() {
	int i,n;
	char a[100];
	gets(a);
	n = strlen(a);
	for(i = 1;i < n;i++) {
		if(find(a,i,n)) {
			printf("%d",i);
			return 0;
		}
	}
	printf("%d",n);
}
