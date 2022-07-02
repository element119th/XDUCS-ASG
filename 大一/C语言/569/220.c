#include<stdio.h>
#include<string.h>
int main(){
    char string[1024];
    gets(string);
    int x=strlen(string);
    printf("%d",x);
    return 0;
}