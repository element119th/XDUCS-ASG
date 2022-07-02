#include<stdio.h>
int main(){
    int n,sum=0,qq1,qq2,a[100];
    int max=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for (int i = 0; i < n; i++)
    {  qq1=a[i];
       while (a[i]!=0)
     {
        sum=sum+(a[i]%10);
        a[i]/=10;
     }
       if (sum>max)
       {
           max=sum;
           qq2=qq1;
       }else if (sum==max)
       {
         qq2=qq2>qq1?qq2:qq1;   
       }
       sum=0;
    }   
       printf("%d",qq2);
       return 0;
}
    
    
