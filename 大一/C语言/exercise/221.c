#include<stdio.h>
void fun(char num[100]){
    int sum1=0,sum2=0;
    int i=0;
    while (num[i]!="2")
    {
        if (num[i]>=48 && num[i]<=57)
         sum1++;
        if (num[i]>=65 && num[i]<=90 || num[i]>=97 && num[i]<=122)
         sum2++;
         i++;
    }
    printf("%d %d",sum2,sum1);
}
int main(){
    char a[100]={"2"};
    scanf("%s",a[100]);
    fun(a[100]);
    return 0;
}