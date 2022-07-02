#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    char data[50]={0};
    int num[2];
    char op;
    gets(data);
    int x=strlen(data);
    int k=0;
    for(int i=0; i<x;i++){
        if(isdigit(data[i])){
        int j=0;
        char temp[10]={0};            
            while (isdigit(data[i]))
            {
                temp[j++]=data[i];
                i++;
            }
            num[k]=atoi(temp);
            k++;
        }
        if(isdigit(data[i])==0&&data[i]!=' '&&data[i]!='\0'){
            op=data[i];
        }
    }
    switch(op){
        case '+':printf("%d",num[0]+num[1]);break;
        case '-':printf("%d",num[0]-num[1]);break;
        case '*':printf("%d",num[0]*num[1]);break;
        case '/':printf("%d",num[0]/num[1]);break;
        case '%':printf("%d",num[0]%num[1]);break;
    }
    return 0;
}