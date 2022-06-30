#include<stdio.h>

typedef struct Dot {
	int i;
	int left = 0;
	int right = 0;
}D; 

void judge(D a[],int i,int b[]) {
	int j = 0;
	if(a[i].left != 0) 
		judge(a,a[i].left,b);
	while(b[j] < 114514) {
		++j;
	}
	b[j] = a[i].i;
	if(a[i].right != 0) 
		judge(a,a[i].right,b);
}

int main() {
	int n,i,t,b[1000];
	D a[1000];
	scanf("%d %d",&n,&t);
	for(i = 0;i < n;i++) b[i] = 114514;
	for(i = 1;i <= n;i++) 
		scanf("%d %d %d",&a[i].i,&a[i].left,&a[i].right);
	judge(a,t,b);
	for(i = 0;i < n-1;i++) {
		if(b[i+1] <= b[i]) {
			printf("false");
			break;
		}
	}
	if(i == n-1) printf("true");
    return 0;
}
