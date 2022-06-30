#include<stdio.h>

typedef struct Queue {
	int a[1000];
	int front = 0;
	int rear = 0;
	int length = 0;
}Q;
typedef struct Queue *Lq;

void in(Lq p,int a) {
	p->a[p->rear] = a;
	p->rear++;
	p->length++;
}

int out(Lq p) {
	int a = p->a[p->front];
	p->front++;
	p->length--;
	return a;
}

int main() {
	int i,j,a[100][100],n,visit[100] = {0},type = 0,count = 0,*t;
	Q q;
	Lq p = &q;
	scanf("%d",&n);
	for(i = 0;i < n;i++) 
		for(j = 0;j < n;j++) scanf("%d",&a[i][j]);
	for(i = 0;i < n;i++) {
		if(!visit[i]) {
			printf("%d ",i+1);
			in(p,i);
			visit[i] = 1;
			type = 1;
		} 
		while(p->length) {
			int t = out(p);
			for(j = 0;j < n;j++) {
				if(a[t][j] != 0 && !visit[j]) {
					printf("%d ",j+1);
					in(p,j);
					visit[j] = 1;
					type = 1;
				}
			}
		}
		if(type == 1) count++;
		type = 0;
	}
	printf("\n%d",count);
	
	return 0;
}
