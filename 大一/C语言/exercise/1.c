#include<stdio.h> 
#include<string.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);
	float a[100],b[100],c[100],num = 0;
	for(int i=2;i<=n;i++){
		a[0] = 2;
		a[1] = 3;
		a[i] = a[i-1]+a[i-2];
    }
		for(int j=2;j<=n;j++){
		b[0] = 1;
		b[1] = 2;
		b[j] = b[j-1]+b[j-2];
        }
			for(int k=2;k<=n;k++){
				c[k] = a[k]/b[k];
			}
	for(int t=0;t<=n;t++){
		num+=c[t];
	}
    printf("%.2f",num);
	return 0;
}