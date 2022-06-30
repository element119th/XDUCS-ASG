#include<stdio.h>
#include<math.h>

int main() {
	int a[1001],n,d,i,res[1000],sum = 0;
	scanf("%d",&n);
	while(n != 0) {
		for(i = 1;i <= n;i++) scanf("%d",&a[i]);
		scanf("%d",&d);
		if(pow(2,d-1) > n) {
			res[sum] = 114514;
			sum++;
		}
		else {
			i = pow(2,d-1); 
			while(i <= n && i < pow(2,d)) {
				res[sum] = a[i];
				sum++;
				i++;
			}
		}
		res[sum] = 1919810;
		sum++;
		scanf("%d",&n);
	}
	
	for(i = 0;i < sum;i++) {
		if(res[i] == 114514) printf("EMPTY");
		else if(res[i] == 1919810) printf("\n");
		else printf("%d ",res[i]); 
	}
	
	return 0;
}
