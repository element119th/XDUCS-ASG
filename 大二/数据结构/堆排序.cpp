#include<stdio.h>

void HeadAdjust(int a[],int s,int n) {
	int i,temp;
	temp = a[s];
	for(i = s * 2;i <= n;i *= 2) {
		if(i < n && a[i+1] < a[i]) 
			i++;
		if(temp <= a[i])
			break;
		a[s] = a[i];
		s = i;
	}
	a[s] = temp;
}

void HeadSort(int a[],int n) {
	int i;
	for(i = n / 2;i > 0;i--) 
		HeadAdjust(a,i,n);
	for(i = n;i > 1;i--) {
		int swap = a[i];
		a[i] = a[1];
		a[1] = swap;
		HeadAdjust(a,1,i-1);
	}
}


int main() {
	int a[1000],n,i;
	scanf("%d",&n);
	for(i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
	}
	HeadSort(a,n);
	for(i = 1;i <= n;i++) {
		printf("%d ",a[i]);
	}
	
	return 0;
}
