#include<stdio.h>
void change(int *p,int x){
    int maxid=0,minid=0;
    int max=0,min=999;
    int k;
    for(int i=0;i<x;i++){
        if(*(p+i)>max){
            max=*(p+i);
            maxid=i;
        }
        if(*(p+i)<min){
            min=*(p+i);
            minid=i;
        }        
    }
    k=*(p+minid);
    *(p+minid)=*(p+maxid);
    *(p+maxid)=k;
}
int main(){
    int num[20];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    change(num,n);
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
    }
    return 0;
    
}