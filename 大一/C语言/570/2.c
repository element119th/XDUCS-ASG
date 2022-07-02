
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
		printf("%d\n", yue(m, n));
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
	current = head->next;//当前current是首元节点了，也就是 1 ，
	for (int i = 1; i < m; i++) //m个人，剩下一个人，所以循环m-1次，每次循环删除一个，
	{
		for (int j = 0; j < n - 1; j++)//开始数数，一共执行n-1次，最后current就是要被应该被删除的（比如8 4，现在current是4，实际上他是以覆盖代删，删除的下一个，也就是5）
		{
			current = current->next;//往下数
		}
		prev = current->next; //用prev记录要被跳过的节点，方便下面释放
		current->number = current->next->number;//将下一个节点（被删除的5）的数转移到上一个节点（4）
		current->next = current->next->next;//跳过下一个节点，指向下下个节点
		free(prev);//释放掉被跳过的节点
	}
	return current->number;
}
