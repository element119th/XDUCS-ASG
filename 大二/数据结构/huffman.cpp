#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int num[1000];
	int top = -1;
}S;

int push(S *p,int n) {
	p->top++;
	p->num[p->top] = n;
}

int pop(S *p) {
	int n = p->num[p->top];
	p->top--;
	return n;
}

void sort(int a[],int n) {
	int i,j,t;
	for(i = 0;i < n;i++) {
		for(j = i + 1;j < n;j++) {
			if(a[j] > a[i]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t; 
			}
		}
	}
}

int main() {
	int a[1000],n,i,sum = 0;
	S s,*p = &s;
	scanf("%d",&n);
	for(i = 0;i < n;i++) scanf("%d",&a[i]);
	sort(a,n);
	for(i = 0;i < n;i++) push(p,a[i]);
	while(p->top > 0) {
		n = pop(p) + pop(p);
		sum += n;
		push(p,n);
		sort(p->num,p->top + 1);
	}
	printf("%d",sum); 
	
	target:return 0;
}
