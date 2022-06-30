#include<stdio.h>

typedef struct queue {
	int a[1000];
	int front=0;
	int rear=0; 
}q; 

int in(int n,q *s) {
	if(s->rear == 1000) s->rear = 0;
	s->a[s->rear] = n;
	s->rear++;
}

int out(q *s) {
	int n=s->a[s->front];
	s->front++;
	if(s->front == 1000) s->rear = 0;
	return n;
}

void sort(q *p,q *s,int n) {
	int i,j,k,temp;
	for(i = 0;i < n;i++) {
		for(j = i;j < n;j++) {
			if(j == i) k = out(p);
			else if(p->a[p->front] < k) {
				temp = k;
				k = out(p);
				in(temp,p);
			}
			else in(out(p),p);
		}
		in(k,s);
	}
}

int main() {
	int i,n,t;
	q a,b,*s = &a,*p = &b;
	scanf("%d",&n);
	for(i = 0;i < n;i++) {
		scanf("%d",&t);
		in(t,s);
	}
	sort(s,p,n);
	for(i = 0;i < n;i++) {
		printf("%d ",out(p));
	}
}
