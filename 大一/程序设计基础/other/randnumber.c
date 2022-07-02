#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand((unsigned)time(NULL));
    int num=rand()%100;
    int guess=-1;
    printf("猜猜这个数是几(100以内)?\n");
    scanf("%d",&guess);
    while (guess!=num)
    {
        if (guess<num)
        {
            printf("too small!\n");
        }else if(guess>num){
            printf("too big!\n");
        }
        scanf("%d",&guess);
    }
    printf("you win!");
    return 0;
}