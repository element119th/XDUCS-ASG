#include<stdio.h>
int main()
{
    int m[16], n, i, t, count=0;
    long unsigned a, k;
    printf("No.    number     it's square(palindrome)\n");
    for( n=1; n<256; n++ )  /*穷举n的取值范围*/
    {
        k=0; t=1; a=n*n;  
        /*计算n
        的平方*/
        for( i=0; a!=0; i++ )  /*从低到高分解数a的每一位存于数组m[1]~m[16]*/
        {
            m[i] = a % 10;
            a /= 10;
        }
        for(; i>0; i--)
        {
            k += m[i-1] * t;  /*t记录某一位置对应的权值 */
            t *= 10;
        }
        if(k == n*n)
            printf("%2d%10d%10d\n", ++count, n, n*n);
    }
    return 0;
}