#include<stdio.h>
#include<string.h>

void sort(int a[],int b[],int c[],int a1,int b1,int b2,int c1,int n) {
	int i,j,k;
	c[c1] = a[a1];
	for(i = b1;i <= b2;i++) {
		if(b[i] == a[a1]) break;
	}
	if(b1 <= i - 1) {
		for(j = 1;j <= n;j++) {
			for(k = b1;k < i;k++) {
				if(a[j] == b[k]) {
					sort(a,b,c,j,b1,i-1,2*c1,n);
					goto target;
				}
			}
		}
	}
	target:if(b2 >= i + 1) {
		for(j = 1;j <= n;j++) {
			for(k = i + 1;k <= b2;k++) {
				if(a[j] == b[k]) {
					sort(a,b,c,j,i+1,b2,2*c1+1,n);
					return;
				}
			}
		}
	}
}

void Print1(int c[],int i) {
	if(c[2*i] == 0 && c[2*i+1] == 0 && c[i] != 0) printf("%d ",c[i]);
	else if(c[i] == 0) return;
	else {
		Print1(c,2*i);
		Print1(c,2*i+1);
	}
}

void Print2(int c[],int i) {
	printf("%d ",c[i]); 
	if(c[2*i] != 0) Print2(c,2*i);
	if(c[2*i+1] != 0) Print2(c,2*i+1);
}

void Print3(int c[],int i) {
	if(c[2*i] != 0) Print3(c,2*i);
	if(c[2*i+1] != 0) Print3(c,2*i+1);
	printf("%d ",c[i]); 																											
}

int main() {
	int n,i,a[2000],b[2000],c[4000] = {0};
	scanf("%d",&n);
	for(i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(i = 1;i <= n;i++) scanf("%d",&b[i]);
	sort(a,b,c,1,1,n,1,n);
	Print1(c,1);
	printf("\n");
	Print2(c,1);
	printf("\n");
	Print3(c,1);
	
	return 0;
}
