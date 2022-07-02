#include<stdio.h>
int main(){
	int n,i=1;
	scanf("%d",&n);
	for(;i<=n*n;i+=2){
		if((n*i+n*(n-1))==n*n*n){
			for(int r=0;r<n;r++){
				printf("%d ",i);
				i+=2;
			}	
		}
	}
	printf("\n");
	return 0;
}