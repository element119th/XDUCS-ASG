#include<stdio.h> 

typedef struct sqstack {
	int num[10000];
	int top;
}st;

int push(st *s,int n) {
	s->top++;
	s->num[s->top] = n;
}

int pop(st *s) {
	s->top--;
}

int judge(int n,int a[],int m,int *num,st *s) {
	int i=*num;
	if(s->top!=-1 && s->num[s->top] == n) {
		pop(s);
		return 1;
	}
	while(a[i] != n) {
		push(s,a[i]);
		i++;
	}
	if(s->top+2 > m) return 0;
	*num = i+1;
	return 1;
}

int main() {
	int m,n,k,i,j,t=0,*num = &t;
	int a[1000],b[1000],p[1000] = {0};
	st c,*s = &c;
	c.top = -1; 
	scanf("%d %d %d",&m,&n,&k);
	for(i = 0;i < n;i++)  scanf("%d",&a[i]);
	for(i = 0;i < k;i++) {
		for(j = 0;j < n;j++) {
			scanf("%d",&b[i]);
		    if(judge(b[i],a,m,num,s) == 0) {
		    	p[i] = 1;
			}
		}
		s->top = -1;
		*num = 0;
	}
	for(i = 0;i < k;i++) {
		if(p[i] == 1) printf("NO\n");
		else printf("YES\n");
	}
}









