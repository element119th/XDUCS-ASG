#include<stdio.h>
#include<string.h>
void count(char a[],char b[]){
    int sum = 0;
    int len=strlen(a);
    for(int i=0;i<=len;i++){
        int k=0;
        char temp[8]={0};
        while(a[i]!=' '){
            temp[k]=a[i];
            k++;
            i++;
            if(i>len){
                break;
            }
        }
        if(strcmp(temp,b)==0){
            sum++;
        }
    }

    printf("%s",b);

    printf(" %d",sum);
}
int main(){
    char string[100]={0};
    char word[9]={0};
    gets(string);
    gets(word);
    count(string,word);
    return 0;
}