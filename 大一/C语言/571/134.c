#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int number[10]={0};
    while (n/10)
    {
        number[n%10]++;
        n/=10;
    }
    number[n]++;
    for (int i = 9; i >=0 ; i--)
    {
        if (number[i])
        {
            printf("%d ",i);
        }
        
    }
    return 0;
}