#include<stdio.h>
#include<stdlib.h>

typedef struct BiTree {
	int i = -1;
	BiTree *left = NULL,*right = NULL; 
}B;
typedef struct BiTree *Lt;

int Insert(Lt p,int num,int i) {
	if(p->i == -1) {
		p->i = num;
		return i;
	}
	else {
		int t = p->i;
		if(num < p->i) {
			if(!p->left) {
				p->left = (Lt)malloc(sizeof(B));
				p = p->left;
				p->i = -1;
				p->left = NULL;
				p->right = NULL;
				return Insert(p,num,t);
			}
			else return Insert(p->left,num,t);
		}
		else if(num > p->i) {
			if(!p->right) {
				p->right = (Lt)malloc(sizeof(B));
				p = p->right;
				p->i = -1;
				p->left = NULL;
				p->right = NULL;
				return Insert(p,num,t);
			}
			else return Insert(p->right,num,t);
		}
		else return -1;
	}
}

void front(Lt p) {
	if(p) {
		printf("%d ",p->i);
		front(p->left);
		front(p->right);
	}
}

void mid(Lt p) {
	if(p) {
		mid(p->left);
		printf("%d ",p->i);
		mid(p->right);
	}
}

void rear(Lt p) {
	if(p) {
		rear(p->left);
		rear(p->right);
		printf("%d ",p->i);
	}
}

int main() {
	int i,k,n;
	B t;
	Lt p = &t;
	scanf("%d",&n);
	for(i = 0;i < n;i++) {
		scanf("%d",&k);
		Insert(p,k,-1);
	}
	front(p);
	printf("\n");
	mid(p);
	printf("\n");
	rear(p);
	
	return 0;
}
