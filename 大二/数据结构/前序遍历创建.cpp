#include<stdio.h>
#include<stdlib.h>

typedef struct BiTree {
    char c;
    struct BiTree *left = NULL;
    struct BiTree *right = NULL;
}T;
typedef T *Lt;

void Create(Lt t) {
    char a;
	a = getchar();
	t->c = a;
	if(a == '#') return;
	t->left = (Lt)malloc(sizeof(T));
	t->right = (Lt)malloc(sizeof(T));
	Create(t->left);
	Create(t->right);
}

void Print(Lt t) {
    if(t->left->c != '#') Print(t->left);
    printf("%c ",t->c);
	if(t->right->c != '#') Print(t->right);
}

int main() {
	char c;
	T p;
	Lt t = &p;
	Create(t);
	Print(t);
	
	return 0;
} 
