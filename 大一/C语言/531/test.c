#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    char a[50];
    char b[50];
    gets(a);
    int x=strlen(a);
    int i=0;
        if(islower(a[i])&&isdigit(a[i+1])){
            int j=0;
            while(isdigit(a[i+1])){
                b[j++]=a[i+1];
                i++;
            }
        }
    puts(b);
    int sum=atoi(b);
    prin
return 0;
}