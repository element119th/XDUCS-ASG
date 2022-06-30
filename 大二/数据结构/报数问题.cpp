#include<stdio.h>

typedef struct node {
    int a[10000];
	int front = 0;
	int rear = 0;
	int length = 0;
}q;

int in(int num,q *s) {
	if(s->rear == 10000) s->rear = 0;
	s->a[s->rear] = num;
	s->rear++;
	s->length++;	
}

int out(q *s) {
	int n=s->a[s->front];
	s->front++;
	if(s->front == 10000) s->front = 0;
	s->length--;
	return n;
}

int main() {
	int i,j,n,t,p;
	q q,*s = &q;
	scanf("%d",&n);
	for(i = 1;i <= n;i++) {
		in(i,s);
	}
	if(s->length > 3) {
	for(j = 2;j <= 3;j++) {
		t = s->front;
		p = s->rear;
		for(i = s->front;i < p;i++) {
			if((i+1 - t) % j == 0) {
				out(s);
			}
			else in(out(s),s);
		} 
		if(s->length <= 3) goto target;
	    if(j == 3) j = 1;
	}
   } 
	target:
		for(i = s->front;i < s->rear;i++) {
			printf("%d ",s->a[i]);
		}
	
	return 0;
}
