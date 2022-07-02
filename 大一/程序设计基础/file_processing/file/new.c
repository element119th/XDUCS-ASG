1#include<stdio.h>
2int main()
3{
4    int m[16], n, i, t, count=0;
5    long unsigned a, k;
6    printf("No.    number     it's square(palindrome)\n");
7    for( n=1; n<256; n++ )  
8    {
9        k=0; t=1; a=n*n;  
10        
11        for( i=0; a!=0; i++ )  
12        {
13            m[i] = a % 10;
14            a  10;
15        }
16        for(; i>0; i--)
17        {
18            k += m[i-1] * t;  
19            t *= 10;
20        }
21        if(k == n*n)
22            printf("%2d%10d%10d\n", ++count, n, n*n);
23    }
24    return 0;
25}