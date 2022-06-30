#include<stdio.h>

typedef struct {                               //边的数据结构 
	int begin;
	int end;
	int weight;
}Edge;

void sort(Edge *a,int n) {                    //图中边的排序算法（选择排序） 
	int i,j;
	for(i = 0;i < n;i++) {
		for(j = i + 1;j < n;j++) {
			if(a[i].weight > a[j].weight) {
				int t1 = a[i].begin,t2 = a[i].end,t3= a[i].weight;
				a[i].begin = a[j].begin;
				a[i].weight = a[j].weight;
				a[i].end = a[j].end;
				a[j].begin = t1;
				a[j].end = t2;
				a[j].weight = t3;
			 }
		}
	}
}

//MFSet 
int Find(int *parent,int f) {             //查找函数， 用于定位最小生成树的根节点 
	while(parent[f]) {
		f = parent[f];
	}
	return f;
}

int max(int a,int b,int type) {           //求两个数中的较大/较小值 
	if(a > b) {
		if(type) return a;
		else return b; 
	}
	if(type) return b;
	else return a; 
}

void kruskal(Edge *a,int parent[],int m) {         //克鲁斯卡尔算法 
	int i,begin,end;
	for(i = 0;i < m;i++) {
		begin = Find(parent,a[i].begin);
		end = Find(parent,a[i].end);
		if(begin != end) {
			parent[begin] = end;              //merge函数，实现归并操作             
			printf("%d %d %d\n",max(a[i].begin,a[i].end,0),max(a[i].begin,a[i].end,1),a[i].weight);
		}
	}
}

int main() {
	int i,m,n;
	scanf("%d %d",&n,&m);                   //输入结点数和边数 
	Edge a[m];
	int parent[n+1];
	for(i = 0;i < m;i++)                    //按边输入图 
		scanf("%d %d %d",&a[i].begin,&a[i].end,&a[i].weight);
    for(i = 0;i < n+1;i++)                  //根节点初始化 
		parent[i] = 0; 
	sort(a,m);                              //按照边的权值排序 
	kruskal(a,parent,m);
	return 0;
}
