#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct students
{
    char identity[20];
    int sumscore;
    int Englishscore;
};
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    struct students scores[m+1];
    struct students temp;
    for (int i = 0; i < m; i++)
    {
        scanf("%s",&scores[i].identity);
        scanf("%d %d",&scores[i].sumscore,&scores[i].Englishscore);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <m-1-i ; j++)
        {
            if (scores[j].sumscore<scores[j+1].sumscore)
            {
                temp=scores[j];
                scores[j]=scores[j+1];
                scores[j+1]=temp;
            }
            if (scores[j].sumscore==scores[j+1].sumscore&&scores[j].Englishscore<scores[j+1].Englishscore)
            {
                scores[m+1]=scores[j];
                scores[j]=scores[j+1];
                scores[j+1]=scores[m+1];
            }
            
            
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d\n",scores[i].identity,scores[i].sumscore,scores[i].Englishscore);
    }
    return 0;

}