#include<stdio.h> 

int BubbleSort (int a[],int n) {
	int i,j,count = 0;
	for(i = 0;i < n - 1;i++) {
		for(j = 0;j < n - i -1;j++) {
			if(a[j] > a[j+1]) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				count++;
			}
		}
	}	
	return count; 
}

int main() {
	int n,i,a[100];
	scanf("%d",&n);
	for(i = 0;i < n;i++) {
		scanf("%d",&a[i]);
	}
	printf("%d",BubbleSort(a,n));
	
	return 0; 
}
