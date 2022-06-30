#include<stdio.h>

int Merge(int a[],int i,int m,int n) {
	int temp[1000],k,b,j;
	b = i;
	for(j = m+1,k = 1;i <= m && j <= n;++k) {
		if(a[i] < a[j]) temp[k] = a[i++];
		else temp[k] = a[j++];
	}
	for(;i <= m;) temp[k++] = a[i++];
	for(;j <= n;) temp[k++] = a[j++];
	for(i = b,k = 1;i <= n;) a[i++] = temp[k++];	
}

int MergeSort(int a[],int i,int n) {
	if(i < n) {
		int m = (i+n) / 2;
		MergeSort(a,i,m);
		MergeSort(a,m+1,n);
		Merge(a,i,m,n);
	}
}

int main() {
	int a[1000],i,n1,n2;
	scanf("%d",&n1);
	scanf("%d",&n2);
	for(i = 1;i <= n1 + n2;++i) scanf("%d",&a[i]);
	Merge(a,1,n1,n1+n2);
	for(i = 1;i <= n1 + n2;++i) printf("%d ",a[i]);
	
	return 0;
}
