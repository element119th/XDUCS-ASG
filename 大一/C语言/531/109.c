#include<stdio.h>
#include<string.h>
int main(){
    char c[100]={0};
    char large[100]={0};
    char little[100]={0};
    gets(c);
    int m=0,n=0;
    int x=strlen(c);
    for(int i=1; i<x;i++){
        if(c[i]>c[0]){
            large[m]=c[i];
            m++;
        }
        if(c[i]<=c[0]){
            little[n]=c[i];
            n++;
        }        
    }
    int len=strlen(little);
    char temp;
    for(int i=0; i<len; i++){
        for(int j=0; j<len-i-1; j++){
            if(little[j]>little[j+1]){
                temp=little[j];
                little[j]=little[j+1];
                little[j+1]=temp;
            }
        }
    }
    int l=0;
    int k=0;
    while (large[l]!=0)
    {
       printf("%c",large[l]);
       l++;
    }
    printf("%c",c[0]);
    while (little[k]!=0)
    {
       printf("%c",little[k]);
       k++;
    }
    return 0;
}