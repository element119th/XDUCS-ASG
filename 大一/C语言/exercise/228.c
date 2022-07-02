#include<stdio.h>
#include<string.h>
void fun(char n[100]){
    int m;
    m=strlen(n);
    printf("%d",m);
    for (int i = 0; i <= m-1; i+=2)
    {
        printf("%c",n[i]);
    }
}
int main(){
    char a[100];
    scanf("%s",a);
    fun(a);
    return 0;
}