#include<stdio.h>

int find(int a,int n) {
    if(n < 4 * a) {
    	if(2*a == n) return 1;
    	else if(2*a + 1 <= n) return 2;
    	else return 0;
	}
	else return find(2*a,n) + find(2*a+1,n) + 2;
}

int main() {
	int i,m,n,a[100] = {0},sum = 0;
	for(i = 0;;i++) {
		scanf("%d %d",&m,&n);
		if(m == 0) break;
		a[i] = find(m,n) + 1;
		sum++; 
	}
	
	for(i = 0;i < sum;i++) printf("%d\n",a[i]);
	
	return 0;
}
