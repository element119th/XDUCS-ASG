#include <stdio.h>
void char_cp(char *a,char *b,int x){
    a+=x+1;
    while (*b++=*a++);
}
int main(){
    char str[50],cp[50];
    int n;
    gets(str);
    scanf("%d", &n);
    char_cp(str,cp,n);
    puts(cp);
    return 0;
}