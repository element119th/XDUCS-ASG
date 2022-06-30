#include<stdio.h>

int Get(int a,int b) {
	if(a == b) return a;
	if(a > b) {
		if(a % 2 == 0) a = a / 2;
		else a = (a - 1) / 2;
	}
	else {
		if(b % 2 == 0) b = b / 2;
		else b = (b - 1) / 2;
	}
    return Get(a,b);
}

int main() {
	int i,m,n,a[100] = {0},sum = 0;
	for(i = 0;;i++) {
		scanf("%d %d",&m,&n);
		if(m == 0) break;
	    a[i] = Get(m,n);
		sum++; 
	}
	
	for(i = 0;i < sum;i++) printf("%d\n",a[i]);
	
	return 0;
}
