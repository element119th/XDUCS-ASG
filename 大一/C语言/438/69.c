#include<stdio.h>
int main(){
    int n=0,m=0;
    int a[100][100]={0};
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    for (int i = 0; i <n; i++)
    {
        int sign=0;
        int start1=0,end1=0,start2=0,end2=0,max=0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j]==1)
            {
                sign=1;
                start1=j;
                while (a[i][j]==1)
                {
                    j++;   
                }
                end1=j-1;
            }
            if (end1-start1+1>=max)
            {
                end2=end1;
                start2=start1;
                max=end1-start1+1;
            }
            
        }
        if (sign==0)
        {
          start2=-1;
          end2=-1;
        }
        printf("%d %d\n",start2,end2);  
    }
    return 0;
}