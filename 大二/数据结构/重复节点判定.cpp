#include<stdio.h>
#include<ctype.h>

typedef struct Dot {
	char c = 0;
	int i = 1;
}D; 

int main() {
	int count = 0,i,j,type = 1;
	char c;
	D a[100];
	while((c = getchar())) {
		if(isalnum(c)) {
			a[count].c = c;
			count++;
		}
		else break;
	}
	for(i = 0;i < count;i++) {
		if(a[i].i) {
			for(j = i+1;j < count;j++) {
				if(a[i].c == a[j].c && a[j].i) {
					if(type) {
						printf("%c:%d",a[i].c,i);
						type = 0;
					}
					printf(",%c:%d",a[j].c,j);
					a[j].i = 0;
				}
			}
			if(!type) printf("\n");
			type = 1;
		}	
	}
    return 0;
}
