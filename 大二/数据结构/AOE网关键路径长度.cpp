#include<stdio.h>

typedef struct Dot {
    int num = 0;
	int visit = 0;	
	int target;
}D;

typedef struct Queue {
	D a[1000];
	int front = 0;
	int rear = 0;
	int length = 0;
}Q;
typedef struct Queue *Lq;

void in(Lq p,D a) {
	p->a[p->rear].num = a.num;
	p->a[p->rear].visit = a.visit;
	p->a[p->rear].target = a.target;
	p->rear++;
	p->length++;
}

void out(Lq p,D *a) {
	a->num = p->a[p->front].num;
	a->visit = p->a[p->front].visit;
	a->target = p->a[p->front].target;
	p->front++;
	p->length--;
}

int main() {
	int i,j,n,a[100][100];
	D b[100],t; 
	Q q;
	Lq p = &q;
	scanf("%d",&n);
	for(i = 0;i < n;i++) 
		for(j = 0;j < n;j++) 
		    scanf("%d",&a[i][j]);   
		    
	for(i = 0;i < n;i++) b[i].target = i;		 //初始化节点编号 
	in(p,b[0]);                                  //将首节点入队列 
	while(p->length != 0) {
		out(p,&t);                               //将当前连接的节点输出作为首节点 
		for(i = 0;i < n;i++) {
			if(a[t.target][i]) {                 //如果存在节点连通则连线 
				if(b[i].visit < n) {             //判断无环则继续计算权值 
					b[i].visit++;
					if(t.num + a[t.target][i] > b[i].num) {        //若连线新生成权值大于最大权值，则新节点作为首节点 
						b[i].num = t.num + a[t.target][i];         
						if(i != n-1) in(p,b[i]);
					}
				}
				else {
					printf("NO");               //有环输出NO 
					goto end;
				}
			}
		}
	}
	printf("%d",b[n-1].num); 
	
	end:
	return 0;
} 
