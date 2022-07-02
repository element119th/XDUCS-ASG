#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if (b==1||b==3||b==5||b==7||b==8||b==10||b==12)
       printf("31");
    if (b==4||b==6||b==9||b==11)
       printf("30");
    if (a%4==0 && a%100!=0 || a%400==0)
    {
        if(b==2)
        printf("29");
    } else if (b==2)
           printf("28");
   return 0; 
}