#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, a[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	float cov = 0;
	for (i = 0; i < n; i++) {
		cov += a[i];
	}
	printf("%.2f\n", cov / (n * 1.0));

	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
		for(int i=0;i<n;i++){
	   if(pm<=50){
	   	a++;
	   }else if(pm<=100){
	   	b++;
	   }else if(pm<=150){
	   	c++;
	   }else if(pm<=200){
	   	d++;
	   }else if(pm<=300){
	   	e++;
	    }else f++;
		}
	printf("%d %d %d %d %d %d", g, b, c, d, e, f);

	system("pause");
	return 0;
}