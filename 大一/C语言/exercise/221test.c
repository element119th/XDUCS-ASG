#include<stdio.h>
int main(){
    char num[100];
    scanf("%s",num);
    int sum1=0,sum2=0;
    int i=0;
    while (num[i]!=0)
    {
        if (num[i]>=48 && num[i]<=57)
         sum1++;
        if (num[i]>=65 && num[i]<=90 || num[i]>=97 && num[i]<=122)
         sum2++;
         i++;
    }
    printf("%d,%d",sum2,sum1);
    return 0;
}
