#include <stdio.h>
int main(){
    int n=0;
    int a[10];
    int sum=0,max=0,min=100;
    float score=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if(a[i]<min){
            min=a[i];
        }
        if(a[i]>max){
            max=a[i];
        }
        sum +=a[i];
    }
    sum=sum-max-min;
    score=(sum*1.0/(n-2));
    printf("%.2f",score);
    return 0;

}