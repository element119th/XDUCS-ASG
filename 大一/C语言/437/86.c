#include<stdio.h>
int main(){
    int b[100][100]={0};
    int n,sum=0;
    int x1,y1,x2,y2;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for (int j = x1; j <x2 ; j++)
        {
            for (int l = y1; l < y2; l++)
            {
                b[l][j]=1;
            }
            
        }
        

    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (b[i][j]==1)
            {
              sum++;
            }
            
        }
        
    }
    printf("%d",sum);
    return 0;
}