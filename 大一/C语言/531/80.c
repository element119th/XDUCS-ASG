#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char std;
    int n;
    char string[100];
    scanf("%c",&std);
    scanf("%d",&n);
    getchar();
    gets(string);
    int total = 0;
    int x=strlen(string);
    if(n == 1){
        for (int i = 0; i < x; i++)
        {
            if(string[i] == std){
                total++;
            }
        }
    }else
    {
        if(isupper(std)){
            std+=32;
        }
        for (int i = 0; i < x; i++){
            if(isupper(string[i])){
                string[i]+=32;
            }
        }
        for (int i = 0; i < x; i++)
        {
            if(string[i] == std){
                total++;
            }
        }        
    }
    printf("%d",total);
    return 0;
}