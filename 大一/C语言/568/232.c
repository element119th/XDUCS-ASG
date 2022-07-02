#include<stdio.h>
#include<string.h>
int main(){
    char str[50];
    gets(str);
    int len=strlen(str);
    int i=0;
    if(len>3){
        while(str[i]==str[len-1-i]){
            i++;
            if(i>=len/2-1){
                break;
            }
        }
        if(i==len/2-1){
            printf("yes");
            return 0;
        }else{
            printf("no");
            return 0;
        }
    }else{
        if(len==1){
            printf("yes");
        }
        if(len==2){
            if(str[0]==str[1]){
                printf("yes");
            }else printf("no");
        }if(len==3){
            if(str[0]==str[2]){
                printf("yes");
            }else printf("no");            
        }
    }
    return 0;
}