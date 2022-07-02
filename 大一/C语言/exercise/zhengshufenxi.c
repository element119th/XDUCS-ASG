#include <stdio.h>
int main() {
	int n, m = 0, t,max=0,min=9;
	scanf("%d", &n);
	if (n==0)
	printf("1 0 0");
	else{
	while (n) {
        t=n%10;
	    max=max>t?max:t;
		min=min<t?min:t;
		n /= 10;
		m++;
	}
	printf("%d %d %d", m, max, min);
	}
	return 0;
}