#include<stdio.h>
#include<math.h>
int fun(int num){
    int x=1;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if(num%i==0) x=0;
    }
    return x;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 2; i < n/2; i++)
    {
        if (fun(i) && fun(n-i)){
            printf("%d %d",i,n-i); 
            break;
        }
        
    }
    return 0;
}