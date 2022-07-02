#include<stdio.h>
int main(){
    char a[100]={"0"};
    int q=0;
    for (int i = 0;; i++)
    {
        scanf("%c,"&a[i]);
        q++;
        if (a[i]=='\n')
        {
            q-=1;
            break;
        }
        if (a[i]==" ")
        {
            scanf("%c",&a[i]);
        }
        
    }
    puts(a);
    return 0;
}