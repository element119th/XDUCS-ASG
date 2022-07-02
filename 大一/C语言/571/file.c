#include<stdio.h>
int main(){

    char str[13][26];
    for (int i = 0; i < 13; i++)
    {
        gets(str[i]);
    }
        for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            printf("%c",str[j][i]);
        }
        printf("\n");
        
    }
    
    return 0;

}
    

