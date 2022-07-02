#include<stdio.h>
#include<string.h>
int main(){
    char str[80]={0};
    char buf[80]={0};
    char temp=0;
    int a[80];
    int len1=0,len2=0;
    gets(str);
    len1 = strlen(str);
    for(int i = 0,j=0; i < len1; i++){
        if(str[i]>=65&&str[i]<=90){
            buf[j]=str[i];
            a[j]=i;
            j++;
        }
        if(str[i]>=97&&str[i]<=122){
            str[i]-=32;
            buf[j]=str[i];
            a[j]=i;
            j++;
        }
    }
    len2 = strlen(buf);
    for(int i = 0; i < len2; i++){
        for(int j = 0; j <len2-1-i;j++){
            if(buf[j]>buf[j+1]){
                temp=buf[j];
                buf[j]=buf[j+1];
                buf[j+1]=temp;
            }
        }
    }
    for(int i=0;i<len2;i++){
        str[a[i]]=buf[i];
    }
    printf("%s\n",str);
    return 0;
}