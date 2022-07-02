#include <stdio.h>
int main(){
    int n=0,x;
    int local=0,max=0;
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        scanf("%d",&x);
        if(x>max){
            local=i;max=x;
        }
    }
    printf("%d %d %d",n,max,local);
    return 0;
}