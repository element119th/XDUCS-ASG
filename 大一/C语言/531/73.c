#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    char zipped[50];
    gets(zipped);
    int x=strlen(zipped);
    for(int i=0; i<x;i++){
        if(islower(zipped[i])!=0&&isdigit(zipped[i+1])==0){
            printf("%c",zipped[i]);
        }
        if(isupper(zipped[i])!=0&&isdigit(zipped[i+1])==0){
            printf("%c",zipped[i]);            
        }
        if(islower(zipped[i])&&isdigit(zipped[i+1])){
            int sum=0,j=0;
            char t[10]={0};
            char temp=zipped[i];
            while(isdigit(zipped[i+1])){
               t[j++]=zipped[i+1];
               i++;
            }
            sum=atoi(t);
            for (int  i = 0; i < sum; i++)
            {
                printf("%c",temp);
            }
        }
        if(isupper(zipped[i])!=0&&isdigit(zipped[i+1])!=0){
            int sum=0,j=0;
            char t[10]={0};
            char temp=zipped[i];
            while(isdigit(zipped[i+1])){
                t[j++]=zipped[i+1];
                i++;
            }
            sum=atoi(t);
            for (int  i = 0; i < sum; i++)
            {
                printf("%c",temp);
            }            
        }

    }
    return 0;
}