#include<stdio.h>
#include<string.h>

void getnext(int next[],char a[]) {
	int i = 0,j = -1,n = strlen(a);
	next[0] = -1;
	while(i < n - 1) {
		if(j == -1 || a[i] == a[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j]; 
	}
}

int getnum(char a[],char b[]) {
	int i = 0,j = 0,sum = 0;
	int na = strlen(a),nb = strlen(b);
	int next[nb];
	getnext(next,b);
	while(i < na) {
		if(j == -1 || a[i] == b[j]) {
			i++;
			j++;
		}
		else
		    j = next[j];
		if(j == nb) {
			j = 0;
			sum++;
		}
	}
	return sum;
}

int main() {
	int i = 0,j;
	char a[1000];
	while((a[i] = getchar()) != EOF) i++;
	
	
	return 0;
}
