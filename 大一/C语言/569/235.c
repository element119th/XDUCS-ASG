#include<stdio.h>
#include<string.h>
int main(){
    char *month[12]={"January", "February", "March", "April", "May","June","July","August","September","October","November","December"};
    int n;
    scanf("%d",&n);
    if(n>12){
        printf("wrong");
        return 0;
    }else{
        puts(month[n-1]);
    }
    return 0;
}