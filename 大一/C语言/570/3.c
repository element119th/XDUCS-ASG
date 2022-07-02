#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	unsigned int number;
	struct node * next;
}* pt,node;

void creat(pt * c, int a);

int yue(int m, int n);

int main ()
{
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF)
	{
		printf("%d\n", yue(m, n%m));
	}
 } 
void creat (pt * c, int a)
{
	pt current, prev;
	* c = (pt) malloc (sizeof(node));
	prev = * c;
	for(int i = 1; a--; i++)
	{
		current = (pt) malloc (sizeof(node));
		current->number = i;
		prev->next = current;
		prev = current ;
	}
	current->next = (*c)->next;
}

int yue(int m,int n)
{
	pt head, current, prev; 
	creat(&head,m);
	current = head->next;
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			current = current->next;
		}
		prev = current->next;
		current->number = current->next->number;
		current->next = current->next->next;
		free(prev);
	}
	return current->number;
}
