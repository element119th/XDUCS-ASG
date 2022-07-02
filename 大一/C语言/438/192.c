#include<stdio.h>
int main(){
    char a[9];
    for (int i = 0; i < 9; i++)
    {
       scanf("%c",&a[i]);
    }
    for (int i = 8; i >=0;i-=2 ){
        printf("%c ",a[i]);
    }
    return 0;
}