#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){
    char string[101];
    char num[101]={0};
    gets(string);
    int len=strlen(string);
    int k=0;
    for(int i=0; i<len; i++){
        if(string[i]>='0'&&string[i]<='9'){
            num[k]=string[i];
            k++;
        }
    }
    int divisormax=0;
    int number = atoi(num);
    for(int i=number-1; i>=1;i--){
        if(number%i==0){
            divisormax=i;
            break;
        }
    }
    if(divisormax==1 || divisormax==0){
        printf("%d",number);
    }else printf("%d",divisormax);
    return 0;
}