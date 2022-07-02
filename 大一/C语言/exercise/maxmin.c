#include<stdio.h>
int main(){
	int a,b,x1=1,x2=1,i;
	scanf("%d%d",&a,&b);
	if(a==0||b==0){
		if(a==0){
			printf("%d",b);
		}else printf("%d",a);		
	}else{
		int min=a<=b?a:b;
		i=min+1;
		while(x1&&x2){
			i--;
			x1=a%i;
			x2=b%i;
		}
		printf("%d",i);
	}
	return 0;
}