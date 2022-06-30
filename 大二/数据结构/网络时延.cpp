#include<stdio.h>

int main() {
	int i,j,n,t1[100],t2[100],count = 0,k,a[100][100],p[100][100],max = 0;
	scanf("%d",&n);
	for(i = 0;i < n;i++) {
		for(j = 0;j < n;j++) {
			scanf("%d",&a[i][j]);
			p[i][j] = j;
		}
	}	
	for(i = 0;i < n;i++) {
		for(j = 0;j < n;j++) {
			for(k = 0;k < n;k++) {
				if(a[j][k] > a[j][i] + a[i][k]) {
					a[j][k] = a[j][i] + a[i][k];	
					p[j][k] = p[j][i];
				}			
			}
		}
	}
	for(i = 1;i;i++) {
		scanf("%d %d",&t1[i],&t2[i]);
		if(t1[i] == -1 && t2[i] == -1) break;
		count++;
	}
	for(i = 1;i <= count;i++) {
		j = t1[i]; k = t2[i];
		if(a[j][k] < 10000) {
			printf("%d\n",a[j][k]);
			printf("%d ",j);
			while(p[j][k] != k) {
				printf("%d ",p[j][k]);
				j = p[j][k];
			}
			printf("%d\n",k);
		}
		else printf("NO\n");
	}
	
	return 0;
}
