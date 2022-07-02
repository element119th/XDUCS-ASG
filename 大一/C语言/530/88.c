#include<stdio.h>
int main(){
    char b[13];
    int a[11];
    int j=1;
    int sum = 0;
    gets(b);
    for(int i = 0; i < 13; i++){
        if(b[i]!='-'){
            if(b[i]=='X'){
                a[j++]=10;
            }else a[j++]=b[i]-48;
        }
    }
    for(int i = 1; i < 10; i++){
        sum+=a[i]*i;
    }
        if(sum%11==a[10]){
            printf("Right");
        }else{
            for(int i = 0; i < 12; i++){
                printf("%c", b[i]);
            }
            if(sum%11==10){
                printf("X");
            }else printf("%d",sum%11);
        }
    return 0;
}