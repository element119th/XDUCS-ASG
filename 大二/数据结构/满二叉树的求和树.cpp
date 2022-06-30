#include<stdio.h>
#include<math.h>

void Create(int a[],int i,int n) {
	if(i > n) return;
	scanf("%d",&a[i]);
	Create(a,2*i,n);
	Create(a,2*i + 1,n);
}

void Print(int a[],int i,int n) {
	if(i > n) return;
	Print(a,2*i,n);
	printf("%d ",a[i]);
	Print(a,2*i + 1,n);
}

int Plus(int a[],int i,int n) {
	if(2*i + 1 <= n) return Plus(a,2*i,n) + Plus(a,2*i+1,n) + a[2*i] + a[2*i+1];
	else return 0;
}

int main() {
	int i,n,a[2000],t;
	char c,b[2000];
	scanf("%d",&n);
	Create(a,1,n);
	c = getchar();
	gets(b);
	
	for(i = 1;i <= n;i++) a[i] = Plus(a,i,n);
	
	Print(a,1,n);
	
	return 0;
}
