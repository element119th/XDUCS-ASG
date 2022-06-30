#include<stdio.h>
#include<stdlib.h>

int main() {
	int i = 0,n,sum = 0;
	char a[1000],c;
	while((c = getchar()) != '#') {
		a[i] = c;
		i++;
	}
	n = i;
	for(i = 1;i <= n;i++) {
		if(2 * i > n && a[i-1] != '@') {
			sum++;
			printf("%c ",a[i - 1]);
		}
		else if(a[i-1] != '@' && a[i*2 - 1] == '@' && a[i*2] == '@'){
			sum++;
			printf("%c ",a[i - 1]);
		}
	}
	printf("\n%d",sum);
	return 0;
}
