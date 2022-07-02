#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a=0,b=0,m;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&m);
        if(i%2!=0) a+=m;
        else if(i%2==0) b+=m;
    }
    if(a>b) printf("Greater than");
    else if(a<b) printf("Less than");
    else if(a=b) printf("Equal");
    return 0;
}