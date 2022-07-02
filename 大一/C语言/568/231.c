#include<stdio.h>
#include<string.h>
int main(){
    char sentence[100]={' '};
    gets(sentence);
    int len = strlen(sentence);
    int max=0;
    for(int i = 0; i < len; i++){
        int wdlen=0;
        while (sentence[i]!=' '&&sentence[i]!=0&&sentence[i]!='.')
        {
            wdlen++;
            i++;
        }
        if (wdlen>max){
            max=wdlen;
        }
    }
    printf("%d",max);
    return 0;
}