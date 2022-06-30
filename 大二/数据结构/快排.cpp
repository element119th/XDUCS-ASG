#include<stdio.h>

int quicksort(int a[], int l, int r) {             //一次划分 
	if (l < r) {
		int i,j,x;
		i = l;
		j = r;
		x = a[i];
		while (i < j) {
			while(i < j && a[j] >= x)
				j--;   // 从右向左找第一个小于x的数
			if(i < j)
				a[i++] = a[j];
			while(i < j && a[i] <= x)
				i++;   // 从左向右找第一个大于x的数
			if(i < j)               //交换元素 
				a[j--] = a[i];
		}
		a[i] = x;       //哨兵归位 
		return i+1;
	}
}

void quick_sort(int a[], int l, int r) {          //快排算法 
	int j;
	if (l >= r) return;
	int i = quicksort(a,l,r);  
	quick_sort(a,l,i-1);        //对哨兵前的数组进行快排 
	quick_sort(a,i,r);         //对哨兵后的数组进行快排 
}

int main() {
	int a[1000],n,i;
	printf("请输入待排序整数个数 ：");
	scanf("%d",&n);
	printf("请输入待排序整数 ：");
	for(i = 0;i < n;i++) scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	printf("排序结果为 ：");
	for(i = 0;i < n;i++) printf("%d ",a[i]);
	
	return 0;
}

