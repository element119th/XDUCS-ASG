#include<stdio.h>
int main(){
    int n=0;
    int sum=0;
    int a[20][20];
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0; i<n; i++){
            sum+=a[i][i];
            sum+=a[n-i-1][i];
    }
    if(n%2==1){
        sum-=a[(n-1)/2][(n-1)/2];
    }
    printf("%d",sum);
}