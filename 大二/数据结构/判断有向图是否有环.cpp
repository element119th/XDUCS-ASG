#include<stdio.h>

int DFS(int a[][100],int i,int n,int count) {
	int j;
	if(count > n) return 0;
	for(j = 0;j < n;j++) {
		if(a[i][j] != 0) {
		    if(DFS(a,j,n,count+1) == 0) return 0;
		}
	}
	return 1;
}

int main() {
	int a[100][100],res[100] = {0},n,t,num,i,j;
	scanf("%d",&n);
	for(t = 0;t < n;t++) {
		scanf("%d",&num);
		for(i = 0;i < num;i++) 
			for(j = 0;j < num;j++) scanf("%d",&a[i][j]);
		for(i = 0;i < num;i++) {
			if(DFS(a,i,num,0) == 0) {
				res[t] = 1;
				break;
			}
		}
	}
	for(t = 0;t < n;t++) printf("%d",res[t]);	
	return 0; 
}
