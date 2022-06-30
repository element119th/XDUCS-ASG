#include<stdio.h>
#include<math.h>

typedef struct node {
	int num;
	int me;
	int next;
	int out = 0;
}Link;

int getnum(Link *p,int n,int num) {
	int i;
	for(i = 0;i < n;i++) {
		if(abs(p[i].num) == abs(num)) return i;
	}
	return -1;
}

int getme(Link *p,int n,int front) {
	int i;
	for(i = 0;i < n;i++) {
		if(p[i].me == front) return i;
	}
}

void sort(Link *p,int n,int front) {
	int i,j,t;
	t = getme(p,n,front);
	for(i = 0;i < n;i++) {
		int c = p[i].me;
		p[i].me = p[t].me;
		p[t].me = c;
		c = p[i].num;
		p[i].num = p[t].num;
		p[t].num = c;
		c = p[i].next;
		p[i].next = p[t].next;
		p[t].next = c;
		c = p[i].out;
		p[i].out = p[t].out;
		p[t].out = c;
		t = getme(p,n,p[i].next);
	}
}

int main() {
	int n,s,i,length,t,sum = 0;
	Link a[100];
	scanf("%d %d",&s,&n);
	length = n;
	for(i = 0;i < n;i++) {
		scanf("%d",&a[i].me);
		scanf("%d",&a[i].num);
		scanf("%d",&a[i].next);
	}
	sort(a,n,s);
	for(i = 1;i < n;i++) {
		t = getnum(a,i,a[i].num);
		if(t != -1) {
			a[i].out = 1;
			length--;
		}
	}
	printf("%d\n",length);
	for(i = 0;i < n;i++) {
		if(a[i].out == 0) {
			if(i!=0) printf("%05d\n",a[i].me);
			printf("%05d ",a[i].me);
			printf("%d ",a[i].num);
			sum++;
			if(sum == length) printf("%d",-1);
		}
	}
}








