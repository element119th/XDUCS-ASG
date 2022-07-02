#include<stdio.h>
int main(){
    int array[10]={1,2,3,4,5,6,7,8,9,10};
    int temp[10]={0};
    int n=0;
    scanf("%d",&n);
    for (int i = 0; i <= n; i++)
    {
        temp[i]=array[i];
    }
    for (int i = n+1; i < 10; i++)
    {
        printf("%d ",array[i]);
    }
    for (int i = 0; i <=n; i++)
    {
        printf("%d ",temp[i]);
    }
    return 0;
}