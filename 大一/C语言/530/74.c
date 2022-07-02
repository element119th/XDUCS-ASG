#include<stdio.h>
#include<string.h>
int judge(char *p,int n){
    int middle=0;
    if (n%2){
        return 0;
    }else {
        middle=n/2;
        for (int i=0;i<middle;i++){
        if(*(p+middle+i)==*(p+middle-1-i))
        return 0;
        } 
    }
    return 1;
}
int main(){
    char str[50]={0};
    char sml[50]={0};
    char mid[50]={0};
    char big[50]={0};
    int sign1=1,sign2=1,sign3=1;
    gets(str);
    int x=strlen(str);
    int a=0,b=0,c=0;
    for(int i=0;i<x;i++){
        if(str[i]=='('||str[i]==')'){
            sml[a]=str[i];
            a++;
        }
        if(str[i]=='['||str[i]==']'){
            mid[b]=str[i];
            b++;
        }
        if(str[i]=='{'||str[i]=='}'){
            big[c]=str[i];
            c++;
        }
    }
    if(a) sign1=judge(sml,a);
    if(b) sign2=judge(mid,b);
    if(c) sign3=judge(big,c);
    if(sign1&&sign2&&sign3){
    printf("yes");
    }else printf("no");
    return 0;
}