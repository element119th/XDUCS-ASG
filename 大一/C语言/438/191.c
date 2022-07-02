#include<stdio.h>
int main(){
    char a[7];
    gets(a);
    for (int i = 0; i < 7; i++)
    {
        if(a[i]>=95&&a[i]<=122){
            a[i]=95+27-(a[i]-95)+2;
        }
        if(a[i]>=65&&a[i]<=90){
            a[i]=65+27-(a[i]-65)-2;
        }
    }
    puts(a);
    return 0;
}