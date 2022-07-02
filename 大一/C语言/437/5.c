#include<stdio.h>
int main(){
    int num[30][30];
    int b[30][30];
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&num[i][j]);
            b[i][j]=num[i][j];
        }
    }
   for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m-1; j++)
        {
            if (num[i][j-1]==num[i][j]&&num[i][j]==num[i][j+1])
            {
                b[i][j-1]=0;
                b[i][j]=0;
                b[i][j+1]=0;
            }
            
        }
    }
   for (int j = 0; j < m; j++)
    {
        for (int i = 1; i < n-1; i++)
        {
            if (num[i-1][j]==num[i][j]&&num[i][j]==num[i+1][j])
            {
                b[i-1][j]=0;
                b[i][j]=0;
                b[i+1][j]=0;
            }
        }
    }   
   for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ",b[i][j]);
        }
        if (i<n-1)
        {
         printf("\n");
        }
    }
    return 0;
}