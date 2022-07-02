#include<stdio.h>
#include<string.h>
int main(){
    char a[100]={0};
    char temp=0;
    gets(a);
    int len=strlen(a);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j <len-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    puts(a);
    return 0;
}