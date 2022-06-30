#include<stdio.h>

void InsertSort(int a[],int dk,int n) {
	int i,j,x;
	for(i = dk;i < n;i++) {
		x = a[i];
		for(j = i - dk;j >= 0 && a[j] > x;j-=dk) {
			a[j+dk] = a[j];
		}
		a[j+dk] = x;
	}
}

void ShellSort(int a[],int num[],int t,int n) {
	int i,j;
	InsertSort(a,num[i],n);
	for(j = 0;j < n;j++) 
		printf("%d ",a[j]);
}

int main() {
	int a[1000],num[1000],n,i,t,j = 0;
	scanf("%d",&n);
	for(i = 0;i < n;i++) {
		scanf("%d",&a[i]);
	}
	for(t = n / 2;t >= 1;t = t / 2) {
		num[j] = t;
		j++;
	}
	ShellSort(a,num,j,n);
	
	return 0;
}
