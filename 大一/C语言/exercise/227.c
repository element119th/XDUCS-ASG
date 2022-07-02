#include<stdio.h>
int main(){
    char num[100];
    scanf("%s",num);
    int sum=0;
    int i=0;
    while (num[i]!=0)
    {
        if (num[i]>=65 && num[i]<=90 || num[i]>=97 && num[i]<=122)
         sum++;
         i++;
    }
    printf("%d",sum);
    return 0;
}
