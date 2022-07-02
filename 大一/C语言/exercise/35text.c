#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 2; i < n/2; i++)
    {
         int x1=1,x2=1;
         for (int j = 2; j <= i; j++)
         {
          if(i%j==0) x1=0;
         } 
         for (int j = 2; j <= n-i; j++)
         {
          if((n-i)%j==0) x2=0;
         }               
          if (x1 && x2){
            printf("%d %d",i,n-i); 
            break;
        }
        
    }
    return 0;
}