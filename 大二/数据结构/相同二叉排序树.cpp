#include<stdio.h>
#include<stdlib.h>

typedef struct BiTree {
	int i;
	BiTree *left = NULL,*right = NULL; 
}B;
typedef struct BiTree *Lt;

int tonum(char a[],int t[]) {
	int i,count = 0;
	for(i = 0;i < 10;i++) {
		if(a[i] >= '0' && a[i] <= '9') {
			t[i] = a[i] - '0';
			count++;
		}
	}
	return count;	
}

int judge(Lt p,Lt s) {
	if(!p && !s) return 0;
	if(!p || !s) return 1;
	if(p->i != s->i) return 1;
	return judge(p->left,s->left) + judge(p->right,s->right);    
}

int main() {
	int n,i,j,k,k1,num[100],numt[100],count[100] = {0};
	char a[100],c;
	B t,t1;
	Lt p = &t,head = &t,head1 = &t1,p1= &t1;
	scanf("%d",&n);
	c = getchar();
	gets(a);
	k = tonum(a,num);
	for(i = 0;i < k;i++) {
		if(i) {
			while(p->i != -1) {
				if(num[i] < p->i) {
					if(!p->left) {
						p->left = (Lt)malloc(sizeof(B));
						p->left->left = NULL;
						p->left->right = NULL;
						p->left->i = -1;
					}
					p= p->left;
				}
				else {
					if(!p->right) {
						p->right = (Lt)malloc(sizeof(B));
						p->right->left = NULL;
						p->right->right = NULL;
						p->right->i = -1;
					}
					p = p->right;
				}
			} 
		}
		p->i = num[i];
		p = head;
	}
	
	for(i = 0;i < n;i++) {
		gets(a);
		k1 = tonum(a,numt);
		if(k1 != k) continue;
		for(j = 0;j < k1;j++) {
			if(j) {
				while(p1->i != -1) {
					if(numt[j] < p1->i) {
						if(!p1->left) {
							p1->left = (Lt)malloc(sizeof(B));
							p1->left->left = NULL;
							p1->left->right = NULL;
							p1->left->i = -1;
						}
						p1 = p1->left;
					}
					else {
						if(!p1->right) {
							p1->right = (Lt)malloc(sizeof(B));
							p1->right->left = NULL; 
							p1->right->right = NULL;
							p1->right->i = -1;
						}
						p1 = p1->right;
					}
				} 
			}
			p1->i = numt[j];
			p1 = head1;
		}
		if(!judge(p,p1)) count[i] = 1;
		t1.left = t1.right = NULL;
	}
	scanf("%d",&i);
	for(i = 0;i < n;i++) {
		if(!count[i]) printf("NO\n");
		else printf("YES\n");
	}
}
