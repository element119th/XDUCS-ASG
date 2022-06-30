#include<stdio.h>
#include<stdlib.h>

#define LH +1
#define EH 0
#define RH -1
#define NULL 0

typedef struct BSTNode {
	int data;
	int bf;
	struct BSTNode *lchild,*rchild;
} BSTNode,*BSTree;

void CreatBST(BSTree &T);
void R_Rotate (BSTree &p);
void L_Rotate(BSTree &p);
void LeftBalance(BSTree &T);
void RightBalance(BSTree &T);
bool InsertAVL(BSTree &T,int e,bool &taller);
bool SearchBST(BSTree &T,int key);
void LeftBalance_div(BSTree &p,int &shorter);
void RightBalance_div(BSTree &p,int &shorter);
void Delete(BSTree q,BSTree  &r,int &shorter);
int DeleteAVL(BSTree &p,int x,int &shorter);
void PrintBST(BSTree T,int depth);

int main() {
	BSTree T;
	int sear,cmd,depth;
	char ch;
	int shorter=0;
	bool taller=false;
	T=(BSTree)malloc(sizeof(BSTNode));
	T=NULL;
	printf("****************平衡二叉树的操作菜单****************\n");
	printf("                    1--创建\n");
	printf("                    2--查找\n");
	printf("                    3--插入\n");
	printf("                    4--删除\n");
	printf("                    5--退出\n");
	printf("****************************************************\n");
	do {
		printf("\n请选择操作的编号：");
		scanf("%d",&cmd);
		getchar();
		switch(cmd) {
			case 1:
				CreatBST(T);
				break;
			case 2:
				printf("请输入您要查找的关键字：");
				scanf("%d",&sear);
				getchar();
				if(SearchBST(T,sear)) printf("关键字%d存在，查找成功!\n",sear);
				else printf("查找失败!\n");
				break;
			case 3:
				printf("请输入您要插入的关键字：");
				scanf("%d",&sear);
				getchar;
				InsertAVL(T,sear,taller);
				depth=0;
				PrintBST(T,depth);
				break;
			case 4:
				depth=0;
				printf("请输入你要删除的关键字: ");
				scanf("%d",&sear);
				getchar();
				DeleteAVL(T,sear,shorter);
				PrintBST(T,depth);
				break;
			case 5:
				printf("结束!\n");
				break;
			default:
				printf("输入错误!\n");
		}
		if(cmd==5)
			break;
		printf("\n继续吗? y/n: ");
		scanf("%s",&ch);
		getchar();
		printf("\n");
	} while(ch=='y');
	printf("\n");
	
	return 0;
}

void CreatBST(BSTree &T) {
	int depth;
	int e;
	bool taller=false;
	T = NULL;
	printf("\n请输入关键字(以-114514结束建立平衡二叉树):");
	scanf("%d",&e);
	getchar();
	while(e != -114514) {
		InsertAVL(T,e,taller);
		printf("\n请输入关键字(以-114514结束建立平衡二叉树):");
		scanf("%d",&e);
		getchar();
		taller=false;
	}
	depth=0;
	printf("\n****************************************************\n");
	printf("                 您创建的二叉树为\n");
	if(T)
		PrintBST(T,depth);
	else
		printf("这是一棵空树!\n");
}

void R_Rotate (BSTree &p) {  //对以*p为根的二叉排序树作右旋处理
	BSTree lc;
	lc=p->lchild;
	p->lchild=lc->rchild;
	lc->rchild=p;
	p=lc;
}

void L_Rotate(BSTree &p) { //对以*p为根的二叉排序树作左旋处理
	BSTree rc;
	rc=p->rchild;
	p->rchild=rc->lchild;
	rc->lchild=p;
	p=rc;
}

void LeftBalance(BSTree &T) {  //对以指针Ｔ所指结点为根的二叉树作左平衡旋转处理
	BSTree lc,rd;
	lc=T->lchild;
	switch(lc->bf) {
		case LH:
			T->bf=lc->bf=EH;
			R_Rotate(T);
			break;
		case RH:
			rd=lc->rchild;
			switch(rd->bf) {
				case LH:
					T->bf=RH;
					lc->bf=EH;
					break;
				case EH:
					T->bf=lc->bf=EH;
					break;
				case RH:
					T->bf=EH;
					lc->bf=LH;
					break;
			}
			rd->bf=EH;
			L_Rotate(T->lchild);
			R_Rotate(T);
	}
}

void RightBalance(BSTree &T) {   //对以指针Ｔ所指结点为根的二叉树作右平衡旋转处理
	BSTree rc,ld;
	rc=T->rchild;
	switch(rc->bf) {
		case RH:
			T->bf=rc->bf=EH;
			L_Rotate(T);
			break;
		case LH:
			ld=rc->lchild;
			switch(ld->bf) {
				case RH:
					T->bf=LH;
					rc->bf=EH;
					break;
				case EH:
					T->bf=rc->bf=EH;
					break;
				case LH:
					T->bf=EH;
					rc->bf=RH;
					break;
			}
			ld->bf=EH;
			R_Rotate(T->rchild);
			L_Rotate(T);
	}
}

bool InsertAVL(BSTree &T,int e,bool &taller) { //插入结点e
	if(!T) {
		T=(BSTree)malloc(sizeof(BSTNode));
		T->data=e;
		T->lchild=T->rchild=NULL;
		T->bf=EH;
		taller=true;
	} else {
		if(e==T->data) {
			taller=false;
			printf("已存在相同关键字的结点!\n");
			return 0;
		}
		if(e<T->data) {
			if(!InsertAVL(T->lchild,e,taller))
				return 0;
			if(taller)
				switch(T->bf) {
					case LH:
						LeftBalance(T);
						taller=false;
						break;
					case EH:
						T->bf=LH;
						taller=true;
						break;
					case RH:
						T->bf=EH;
						taller=false;
						break;
				}
		} else {
			if(!InsertAVL(T->rchild,e,taller))
				return 0;
			if(taller)
				switch(T->bf) {
					case LH:
						T->bf=EH;
						taller=false;
						break;
					case EH:
						T->bf=RH;
						taller=true;
						break;
					case RH:
						RightBalance(T);
						taller=false;
						break;
				}
		}
	}
}

bool SearchBST(BSTree &T,int key) { //查找元素key是否在树Ｔ中
	if(!T)
		return false;
	else if(key==T->data)
		return true;
	else if(key<T->data)
		return SearchBST(T->lchild,key);
	else
		return SearchBST(T->rchild,key);
}

void LeftBalance_div(BSTree &p,int &shorter) {   //删除结点时左平衡旋转处理
	BSTree  p1,p2;
	if(p->bf==1) {
		p->bf=0;
		shorter=1;
	} else if(p->bf==0) {
		p->bf=-1;
		shorter=0;
	} else {
		p1=p->rchild;
		if(p1->bf==0) {
			L_Rotate(p);
			p1->bf=1;
			p->bf=-1;
			shorter=0;
		} else if(p1->bf==-1) {
			L_Rotate(p);
			p1->bf=p->bf=0;
			shorter=1;
		} else {
			p2=p1->lchild;
			p1->lchild=p2->rchild;
			p2->rchild=p1;
			p->rchild=p2->lchild;
			p2->lchild=p;
			if(p2->bf==0) {
				p->bf=0;
				p1->bf=0;
			} else if(p2->bf==-1) {
				p->bf=1;
				p1->bf=0;
			} else {
				p->bf=0;
				p1->bf=-1;
			}
			p2->bf=0;
			p=p2;
			shorter=1;
		}
	}

}

void RightBalance_div(BSTree &p,int &shorter) {  //删除结点时右平衡旋转处理
	BSTree  p1,p2;
	if(p->bf==-1) {
		p->bf=0;
		shorter=1;
	} else if(p->bf==0) {
		p->bf=1;
		shorter=0;
	} else {
		p1=p->lchild;
		if(p1->bf==0) {
			R_Rotate(p);
			p1->bf=-1;
			p->bf=1;
			shorter=0;
		} else if(p1->bf==1) {
			R_Rotate(p);
			p1->bf=p->bf=0;
			shorter=1;
		} else {
			p2=p1->rchild;
			p1->rchild=p2->lchild;
			p2->lchild=p1;
			p->lchild=p2->rchild;
			p2->rchild=p;
			if(p2->bf==0) {
				p->bf=0;
				p1->bf=0;
			} else if(p2->bf==1) {
				p->bf=-1;
				p1->bf=0;
			} else {
				p->bf=0;
				p1->bf=1;
			}
			p2->bf=0;
			p=p2;
			shorter=1;
		}
	}
}

void Delete(BSTree q,BSTree  &r,int &shorter) {       //删除结点
	if(r->rchild==NULL) {
		q->data=r->data;
		q=r;
		r=r->lchild;
		free(q);
		shorter=1;
	} else {
		Delete(q,r->rchild,shorter);
		if(shorter==1)
			RightBalance_div(r,shorter);
	}
}

int DeleteAVL(BSTree &p,int x,int &shorter) {    //平衡二叉树的删除操作
	int k;
	BSTree q;
	if(p==NULL)  {
		printf("不存在要删除的关键字!\n");
		return 0;
	} else if(x<p->data) {
		k=DeleteAVL(p->lchild,x,shorter);
		if(shorter==1)
			LeftBalance_div(p,shorter);
		return k;
	} else if(x>p->data) {
		k=DeleteAVL(p->rchild,x,shorter);
		if(shorter==1)
			RightBalance_div(p,shorter);
		return k;
	} else {
		q=p;
		if(p->rchild==NULL) {
			p=p->lchild;
			free(q);
			shorter=1;
		} else if(p->lchild==NULL) {
			p=p->rchild;
			free(q);
			shorter=1;
		} else {
			Delete(q,q->lchild,shorter);
			if(shorter==1)
				LeftBalance_div(p,shorter);
			p=q;
		}
		return 1;
	}
}

void PrintBST(BSTree T,int depth) {
	int i;
	if(T->rchild)
		PrintBST(T->rchild,depth+1);
	for(i=1; i<=depth; i++)
		printf("     ");
	printf("%d\n",T->data);
	if(T->lchild)
		PrintBST(T->lchild,depth+1);
}
