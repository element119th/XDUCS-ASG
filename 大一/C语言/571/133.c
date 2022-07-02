#include<stdio.h>
struct data
{
    int coeff=0;
    int index=0;
};

int main(){
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);
    struct data formula1[2*n],formula2[2*m],formula[20];
    int forward[20]={0},backward[20]={0},final[20]={0};
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&formula1[i].coeff,&formula1[i].index);
    }
    for(int i = 0; i < m; i++)
    {  
        scanf("%d%d",&formula2[i].coeff,&formula2[i].index);
    }
    int max=m>n?m:n;
    int min=m>n?n:m;
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j <min  j++)
        {
            if()
        }
        
        
    }
    
    return 0;
    
}