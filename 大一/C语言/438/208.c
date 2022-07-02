#include<stdio.h>
void sort(int *a,int x){
    int temp=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<x-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            if(a[j]%2==0&&a[j+1]%2){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;                
            }
        }
    }
}
int main(){
    int num[20]={0};
    int n;
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        scanf("%d",&num[i]);
    }
    sort(num,n); 
    for(int i=0; i<n;i++){
        if(num[i-1]%2&&num[i]%2==0){
            printf("  ");
        }
        printf("%d ",num[i]);
    }
    return 0;
}