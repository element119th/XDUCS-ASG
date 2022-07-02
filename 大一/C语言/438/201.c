#include <stdio.h>
int main(){
    int a[10]={0};
    int b[9]={0};
    int i=0;
    for (int i = 0; i < 10; i++)
    {
       scanf("%d",&a[i]);
    }
    for ( i = 0; i < 10; i++){
        b[i]=a[i+1]/a[i];
    }
    for ( i = 0; i < 9; i++)
    {
        printf("%d ",b[i]);
    }
    
    return 0;
}