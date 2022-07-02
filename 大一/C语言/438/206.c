#include<stdio.h>
#include<string.h>
void dele(char a[],char d){
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (a[i] == d){
            a[i]=0;
        }
    }
    for (int i = 0; i < len; i++){
        if(a[i] !=0 ){
            printf("%c",a[i]);
        }
    }
}
int main(){
    char str[50]={0};
    char ch=0;
    gets(str);
    scanf("%c",&ch);
    dele(str,ch);
    return 0;
}