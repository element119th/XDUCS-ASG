#include<stdio.h>
int main(){
    int n=0,m=0;
    int a[100][100];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=n-1;j>=0;j--){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}