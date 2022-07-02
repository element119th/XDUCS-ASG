#include<stdio.h>
#include<string.h>
void count(char *p,int *q,int n){
    for(int i=0;i<n;i++){
        if(*(p+i)>='A'&&*(p+i)<='Z'){
            (*q)++;
        }else if(*(p+i)>='a'&&*(p+i)<='z'){
            (*(q+1))++;
        }else if(*(p+i)==' '){
            (*(q+2))++;
        }else if(*(p+i)>='1'&&*(p+i)<='9'){
            (*(q+3))++;
        }else (*(q+4))++;
    }
}
int main(){
    char string[100];
    int num[5]={0};
    gets(string);
    int len=strlen(string);
    count(string,num,len);
    for(int i=0;i<5;i++){
        printf("%d ",num[i]);
    }
    return 0;
}