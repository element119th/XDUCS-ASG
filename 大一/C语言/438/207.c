#include<stdio.h>
#include<string.h>
void wd_sort(char (*p)[21],int x){
     char temp[20]={0};
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x-1-i; j++){
            if(strcmp(*(p+j),*(p+j+1))==1){
                strcpy(temp,*(p+j));
                strcpy(*(p+j),*(p+j+1));
                strcpy(*(p+j+1),temp);
            }
        }
    }
}
int main(){
    int n=0;
    char str[10][21]={0};
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",&str[i]);
    }
    wd_sort(str,n);
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n",str[i]);
    } 
    return 0;
}