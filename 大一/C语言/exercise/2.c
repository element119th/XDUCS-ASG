#include<stdio.h> 
#include<string.h>
#include<math.h>
int main(){
	int a,b,c;
	scanf("%d",&a) ;
	for(int j=2;j<=a/2;j++){
		int flag=0;
		for(int i=2;i<=a/2;i++){
		if(j%i==0){
			flag++;
			}
	    }
		int fla=0;
		for(int i=2;i<=(a-j)/2+1;i++){
		if((a-j)%i==0){
			fla++;
		}
	}
		if(fla==1&&flag==1){
		printf("%d %d",j,(a-j));
        return 0;
		}
	}
    return 0;
}