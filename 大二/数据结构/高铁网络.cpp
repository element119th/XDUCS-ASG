#include<stdio.h>

int find(int parent[],int f) {
	while(parent[f]) {
		f = parent[f];
	}
	return f;
}

int main() {
	int i,m,n,j,k,parent[2000] = {0},sum = 0;
	scanf("%d %d",&m,&n);
	for(i = 1;i <= n;i++) {
		scanf("%d %d",&j,&k);
		j = find(parent,j);
		k = find(parent,k);
		if(j != k) 
			parent[j] = k;
		else sum++;
	}
	printf("%d",m - n - 1 + sum);
	
	return 0;
}
