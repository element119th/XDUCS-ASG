#include<stdio.h>
int main(){
    int n=0,m=0,t=0,k=0;
    int a[20][20]={0};
    int b[50]={0};
    int x1=0,y1=0,x2=0,y2=0;
    int sum=0;
    int sign=0;
    scanf("%d %d %d %d",&n,&m,&t,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            if(sign==0&&a[i][j]==k){
                sign=1;
                x1=j;y1=i;
            }
            if(sign==1&&a[i][j]==k){
                x2=j;y2=i;
            }
        }
    }
    for(int i=x1;i<=x2;i++){
        if(y1-1>=0){
        b[a[y1-1][i]]++;
        }
        if(y2+1<n){
        b[a[y2+1][i]]++;
        }
    }
    for(int i=y1;i<=y2;i++){
        if(x1-1>=0){
        b[a[i][x1-1]]++;
        }
        if(x2+1<m){
        b[a[i][x2+1]]++;
        }
    }
    for(int i=1;i<=t;i++){
        if(b[i]!=0){
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}