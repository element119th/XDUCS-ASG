#include<stdio.h>
int main(){
    int n = 0;
    int a[100][100]={0};
    int line = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    line=2*n-1;
    for (int i = 0; i <line; i++)
    {
        if(i%2){
            for (int j = 0; j < n; j++)
            {
                if(j<n&&i-j<n&&i-j>=0){
                    printf("%d ",a[j][i-j]);
                }
            }
        }else{
            for (int j = 0; j < n; j++)
            {
                if(j<n&&i-j<n&&i-j>=0){
                    printf("%d ",a[i-j][j]);
                }
            }            
        }
    }
    return 0;
}