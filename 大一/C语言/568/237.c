#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    char cpy[100];
    char *p=str;
    int m;
    int len;
    gets(str);
    scanf("%d", &m);
    len=strlen(str);
    if(m>=len){
        puts("error");
        return 0;
    }
    strcpy(cpy, p+m-1);
    puts(cpy);
    return 0;
}