#include<stdio.h>
#include<string.h>
int main(){
    char a[8];
    char b[8];
    gets(a);
    gets(b);
    printf("%d",strcmp(a,b));
    return 0;

}