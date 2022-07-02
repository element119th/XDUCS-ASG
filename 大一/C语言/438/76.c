#include<stdio.h>
int main(){
    int n=0;
    int temp=0;
    int a[30]={0};
    int b[100000]={0};
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        b[a[i]]++;
    }
    for(int i=0; i<=a[n-1]; i++){
        if(b[i]){
            printf("%d:%d\n",i,b[i]);
        }
    }
    return 0;
}