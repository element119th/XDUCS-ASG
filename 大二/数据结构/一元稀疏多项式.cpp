#include<stdio.h>  
#include<stdlib.h>

typedef struct MultiNum {
	int M;
	int X; 
	struct MultiNum *next;
}Num;
typedef struct MultiNum *LinkList;

int GetElem(LinkList L,int *M,int *X,int n) {
	int i;
	LinkList p;
	p = L->next;
	for(i = 1;i < n;i++) {
		p = p->next;
	}
	*M = p->M;
	*X = p->X;
	return 1; 
} 

int ChangeElem(LinkList L,int n) {
	int i;
	LinkList p;
	p = L->next;
	for(i = 1;i < n;i++) {
		p = p->next;
	}
	p->M = 9999;
	return 1; 
} 

int ListInsert(LinkList L,int n,int M,int X) {
	int i;
	LinkList p,s;
	p = L;
	for(i = 1;i < n;i++) {
		p = p->next;
	}
	s = (LinkList)malloc(sizeof(Num));
	s->next = p->next;
	p->next = s;
	s->M = M;
	s->X = X; 
	return 1;
}

void rank(LinkList *L,int n) {
	int i,j,swapM,swapX;
	LinkList p,s,q;
	p = *L;
	s = (*L)->next;
	q = s;
	for(i = 0;i < n;i++) {
		for(j = i+1;j < n;j++) {
			if(q->M < p->M) {
				swapM = q->M;
				swapX = q->X;
				q->M = p->M;
				q->X = p->X;
				p->M = swapM;
				p->X = swapX;
			}
			q = q->next;
		}
		s = s->next;
		q = s;
		p = p->next;
	}
}

int main() {
	int i,j,k,sum1 = 0,sum2 = 0,count1 = 0,count2 = 0,n[2],a[6] = {0},func,num01 = 0,num02 = 0,record;
	LinkList head[4],p[4],s,temp1,temp2;
	int *M1,*X1,*M2,*X2,*M3,*X3;
	M1 = &a[0];
	M2 = &a[1];
	M3 = &a[2];
	X1 = &a[3];
	X2 = &a[4];
	X3 = &a[5];
	head[2] = (LinkList)malloc(sizeof(Num));
	p[2] = (LinkList)malloc(sizeof(Num));
	head[2]->next = p[2];
	head[3] = (LinkList)malloc(sizeof(Num));
	p[3] = (LinkList)malloc(sizeof(Num));
	scanf("%d %d %d",&n[0],&n[1],&func);
	head[3]->next = p[3];
	for(i = 0;i < 2;i++) {
		head[i] = (LinkList)malloc(sizeof(Num));
		p[i] = (LinkList)malloc(sizeof(Num));
		head[i]->next = p[i];
		for(j = 0;j < n[i];j++) {
			scanf("%d %d",&p[i]->X,&p[i]->M);
			p[i]->next = (LinkList)malloc(sizeof(Num));
			p[i] = p[i]->next;
		}
	}
	rank(&head[0]->next,n[0]);
	rank(&head[1]->next,n[1]);
	for(k = 1;k <= n[0];k++) {
		GetElem(head[0],M1,X1,k);
		p[2]->M = *M1;
		p[2]->X = *X1;
		p[3]->M = *M1;
		p[3]->X = *X1;
		for(j = 1;j <= n[1];j++) {
			GetElem(head[1],M2,X2,j);
			if(*M2 < *M1) {
				ListInsert(head[2],k+sum1+count1,*M2,*X2);  
				sum1++;
				ListInsert(head[3],k+sum2+count2,*M2,-(*X2));  
				sum2++;
				ChangeElem(head[1],j);
			}
			if(*M2 == *M1) {
				p[2]->X += *X2;
				if(p[2]->X == 0) {
					sum1--;
					count1++;
				}
				p[3]->X -= *X2;
				if(p[3]->X == 0) {
					sum2--;
					count2++;
				}
				ChangeElem(head[1],j);
				break;
			}
	    }
	    p[2]->next = (LinkList)malloc(sizeof(Num));
		p[2] = p[2]->next;
		p[3]->next = (LinkList)malloc(sizeof(Num));
		p[3] = p[3]->next;
	}
	GetElem(head[0],M1,X1,n[0]);
	
	for(j = 1;j <= n[1];j++) {
		GetElem(head[1],M2,X2,j);
		if(*M2 > *M1 && *M2 != 9999) {
			ListInsert(head[2],k+sum1+count1,*M2,*X2);  
			sum1++;
			ListInsert(head[3],k+sum2+count2,*M2,-(*X2));  
			sum2++;
			ChangeElem(head[1],j);
		}
	}
	
	if(func == 0) {
	    for(k = 1;k <= n[0] + sum1 + count1;k++) {
		    GetElem(head[2],M3,X3,k);
		    if(*X3 != 0) {
		    	if(*X3 > 0 && k != 1 && (record != 0 || num01 != k-1)) printf("+");
		    	if(*X3 == -1 && *M3 != 0) printf("-");
		    	if((*X3 != 1 && *X3 != -1)|| *M3 == 0) printf("%d",*X3);
		    	if(*M3 != 0) printf("x");
		    	if(*M3 != 0 && *M3 != 1) printf("^%d",*M3);
			}   
			else num01++;
			record = *X3; 
	    }
	    if(num01 == n[0] + sum2 + count2) printf("0");
	}
	
	if(func == 1) {
	    for(k = 1;k <= n[0] + sum2 + count2;k++) {
		    GetElem(head[3],M3,X3,k);
		    if(*X3 != 0) {
		    	if(*X3 > 0 && k != 1 && !(record == 0 && num02 == k-1)) printf("+");
		    	if(*X3 == -1 && *M3 != 0) printf("-");
		    	if((*X3 != 1 && *X3 != -1)|| *M3 == 0) printf("%d",*X3);
		    	if(*M3 != 0) printf("x");
		    	if(*M3 != 0 && *M3 != 1) printf("^%d",*M3);
			}
			else num02++;
			record = *X3;   
	    }
	    if(num02 == n[0] + sum2 + count2) printf("0");
	}		
	return 0;
}

