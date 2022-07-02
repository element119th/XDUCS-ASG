#include <stdio.h>

int main()
{
    int a,b,n;
    scanf("%d%d",&a,&b);
    if (a==0||b==0)
    {
        n=a==0?b:a;
        printf("%d",n);
    }else{    
    while(a!=b)
    {        
        if(a>b)
        a = a - b;
        if(a<b)
        b = b - a;
    }
    printf("%d",a);
    }
    return 0;
}