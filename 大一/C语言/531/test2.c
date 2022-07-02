#include<stdio.h>
#include<stdlib.h>
int main(){
    char a[9]="12345678";
    char b[9]={1,2,3,4,5,6,7,8};
    int x=atoi(a);
    printf("%d\n",x);
    puts(a);
    puts(b);
    return 0;
}