#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char string[100];
    char cmp[100][100];
    char cmp2[100][100];
    int flag=0,num=0;
    gets(string);
    scanf("%d",&flag);
    scanf("%d",&num);
    getchar();
    for(int i=0;i<num;i++){
        gets(cmp[i]);
        strcpy(cmp2[i],cmp[i]);
        if(flag==0){
            int x=strlen(cmp2[i]);
            int y=strlen(string);
            for(int j=0;j<y;j++){ 
                if(isupper(string[j])){
                    string[j]+=32;
                }
            }
            for(int j=0;j<x;j++){ 
                if(isupper(cmp2[i][j])){
                    cmp2[i][j]+=32;
                }
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        if(strstr(cmp2[i],string)!=NULL){
            puts(cmp[i]);
        }
    }
    
    return 0;
}