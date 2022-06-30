#include<stdio.h>

int DFS(int i,int n,int a[][100],int visit[]) {
	int j,type = 0;
	for(j = 0;j < n;j++) {
		if(a[i][j] && !visit[j]) {
			visit[j] = 1;
			printf("%d ",j+1);
			DFS(j,n,a,visit);
		}
	}		    
}

int main() {
	int i,j,n,a[100][100],visit[100] = {0},type = 0,count = 0; 
	scanf("%d",&n);
	for(i = 0;i < n;i++) 
		for(j = 0;j < n;j++) scanf("%d",&a[i][j]);
	for(i = 0;i < n;i++) {
		if(!visit[i]) {
			visit[i] = 1;
			printf("%d ",i+1);
			DFS(i,n,a,visit);
			type = 1;
		}
		if(type) {
			count++;
			type = 0;
		}
	}
	printf("\n%d",count);
	 
	return 0;
}
