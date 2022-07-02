#include<stdio.h>
#include<string.h>
int main(){
    char n[100];
    int m,sum=0;
    scanf("%s",&n);
    m=strlen(n);
    for (int i = 0; i < m; i++)
        sum+=n[i];
    
    printf("%d",sum&255);
    return 0;
    
}