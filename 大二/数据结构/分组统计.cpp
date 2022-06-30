#include<stdio.h>
#include<stdlib.h>

typedef struct Num {
	int num;
	int group;
	int visit = 0;
}N;

typedef struct Number {
	Number *next;
	int num;
	int visit = 0;
}Nb;
typedef struct Number *Ln;

typedef struct Group {
	Nb *next;
	int num = 0;
}G;

void sort(N a[],int n) {
	int i,j;
	for(i = 0;i < n;i++) {
		for(j = i + 1;j < n;j++) {
			if(a[j].num < a[i].num) {
				int t1 = a[i].num;
				a[i].num = a[j].num;
				a[j].num = t1;
				int t2 = a[i].group;
				a[i].group = a[j].group;
				a[j].group = t2;
			}
		}
	}
}

void sortg(N a[],int n) {
	int i,j;
	for(i = 0;i < n;i++) {
		for(j = i + 1;j < n;j++) {
			if(a[j].group < a[i].group) {
				int t1 = a[i].num;
				a[i].num = a[j].num;
				a[j].num = t1;
				int t2 = a[i].group;
				a[i].group = a[j].group;
				a[j].group = t2;
			}
		}
	}
}

int main() {
	int i,j,n,t,num[100] = {0};
	G gp[100];
	N a[100];
	Ln p;
	scanf("%d",&n);
	while(n--) {
		int count = 0,gc = 0,gf = 0;
		scanf("%d",&t);
		for(i = 0;i < t;i++) 
			scanf("%d",&a[i].num);
		for(i = 0;i < t;i++) 
			scanf("%d",&a[i].group);
		sort(a,t);
		for(i = 0;i < t;i++) {
			if(a[i].num != num[count]) {
				if(i != 0) count++;
				num[count] = a[i].num;
			}
		}
		count++;
		sortg(a,t);
		for(i = 0;i < t;i++) {
			if(a[i].group != gp[gc].num) {
				if(i != 0) gc++;
				gp[gc].num = a[i].group;
			}
		}
		gc++;
		for(i = 0;i < gc;i++) {
			gp[i].next = (Ln)malloc(sizeof(Nb));
			p = gp[i].next;
			for(j = 0;j < count;j++) {
				p->visit = 0;
				p->num = num[j];
				p->next = (Ln)malloc(sizeof(Nb));
				p = p->next;
			}
		}
		for(i = 0;i < t;i++) {
			if(a[i].group == gp[gf].num) {
				p = gp[gf].next;
				while(a[i].num != p->num) p = p->next;
				p->visit++;
			}
			else {
				gf++;
				p = gp[gf].next;
				while(a[i].num != p->num) p = p->next;
				p->visit++;
			}
		}
		for(i = 0;i < gc;i++) {
			printf("%d={",gp[i].num);
			p = gp[i].next;
			for(j = 0;j < count;j++) {
				if(j != count - 1) printf("%d=%d,",p->num,p->visit);
				else printf("%d=%d}\n",p->num,p->visit);
				p = p->next;
			}
		}
	}
} 
