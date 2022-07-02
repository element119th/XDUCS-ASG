#include<stdio.h>
#include<string.h>
void wd_sort(char (*p)[20],int x){
    char temp[20];
    for(int i=0;i<x;i++){
        for(int j=0;j<x-i-1;j++){
            if(strcmp(*(p+j),*(p+j+1))>0){
                strcpy(temp,*(p+j));
                strcpy(*(p+j),*(p+j+1));
                strcpy(*(p+j+1),temp);
            }
        }
    }
}
int main(){
    char str[10][20];
    int n;
    scanf("%d\n", &n);
    for(int i=0; i<n; i++){
        gets(str[i]);
    }
    wd_sort(str,n);
    for(int i=0; i<n; i++){
        puts(str[i]);
        printf("\n");
    }
    return 0;
}