#include<stdio.h>  
#include<stdlib.h>

int length = 0;
typedef struct Seccode {
	int num;
	int order;
	struct Seccode *next;
}Code;
typedef struct Seccode *LinkList;

int GetElem(LinkList L,int n,int *order) {
	int i;
	LinkList p;
	p = L->next;
	if(n == 1) {
		for(i = 0;i < length;i++) {
		    p = p->next;
	    }
	}	
	for(i = 1;i < n;i++) {
		p = p->next;
	}
	*order = p->order;
	//printf("get: p = %d\n",p->num);
	return p->num; 
} 

int ListDel(LinkList *L,int n) {
	int i;
	LinkList p,s;
	p = *L;
	if(n == 1) {
		for(i = 0;i < length;i++) {
		    p = p->next;
	    }
	}
	for(i = 1;i < n;i++) {
		p = p->next;
	}
	s = p->next;
	*L = s;
	p->next = s->next; 
	//printf("del & next p : p = %d\n",L->num);
	return 1;
}

int main() {
	int i,n,m,t,temp = 1;
	int *order;
	LinkList head,p,*q;
	order = &temp;
	head = (LinkList)malloc(sizeof(Code));
	p = (LinkList)malloc(sizeof(Code));
	scanf("%d %d",&n,&m);
	length = n;
	scanf("%d",&head->num);
	head->next = p;      	
	for(i = 0;i < n-1;i++) {
		scanf("%d",&p->num);
		p->order = i+2;
		p->next = (LinkList)malloc(sizeof(Code));
		p = p->next;
	}	
	p->num = head->num;
	p->order = 1;
	p->next = head->next;
	for(i = 0;i < n;i++) {
		if(i == 0) {
		    if(m == 1) { 
			    t = GetElem(p,n,order);
			    q = &p;
		        ListDel(q,n);
		        length--;
		    }
		    else {
			    t = GetElem(p,m-1,order);
			    q = &p;
		        ListDel(q,m-1);
		        length--;
		    }
		}
		else {
			//printf("get & del next :%d %d\n",p->num,m);
		    t = GetElem(p,m,order);
		    q = &p;
		    ListDel(q,m);
		    //printf("get & del next :%d %d\n",p->num,m);
		    length--;
		}
		m = t;
		printf("%d ",*order);
	}
	return 0;
}
