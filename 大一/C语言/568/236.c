#include<stdio.h>
#include<string.h>
int main(){
    char str[200]={'\0'};
    gets(str);
    char *p = str;
    int sum = 0;
    while(*p != '\0'){
        p++;
        sum++;
    }
    printf("%d",sum);
    return 0;
}