#include<stdio.h>
#include<string.h>
int main(){
    char cmd[255];
    char a[200][10]={'\0'};
    gets(cmd);
    int x=strlen(cmd);
    int k=0;
    for(int i=0; i<x;i++){
        if(cmd[i]=='-'){
            int j=0;
            while (cmd[i]!=' ')
            {
                a[k][j]=cmd[i];
                j++;
                i++;
            }
            k++;
        }
    }
    if(k==0){
        printf("no");
        return 0;
    }
    char temp[10];
    for(int i=0; i<k;i++){
        for(int j=0; j<k-1-i;j++){
            if(strcmp(a[j],a[j+1])>0){
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
            }
        }
    }
    for(int i=0;i<k;i++){
        int j=0;
        if(strcmp(a[i],a[i+1])==0){
            i++;
        }
        while(a[i][j]!=0){
            printf("%c",a[i][j]);
            j++;
        }
        printf(" ");
    }
    return 0;
}