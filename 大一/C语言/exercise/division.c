#include<stdio.h>
int main(){
    int n,m=1;
    int a[1000];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    scanf("%d",&a[i]);
    for (int i = 0; i < n-1; i++)
    {
        if(a[i]!=a[i+1])
        m++;
    }
    printf("%d",m);
    return 0;
}