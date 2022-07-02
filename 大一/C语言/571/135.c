#include<stdio.h>
#include<stdlib.h>
int main(){
    char string[100];
    int num[50]={-1};
    int index=0;
    int temped=0;
    gets(string);
    for (int  i = 0; i < 100; i++)
    {
        if(string[i]>'0'&&string[i]<='9'){
            char temp[10]={-1};
            int k=0;
            while (string[i]>'0'&&string[i]<='9')
            {

                temp[k]=string[i];
                i++;
                k++;
            }
            num[index]=atoi(temp);
            index++;
        }
        
    }
    for (int i = 0; i < index+1; i++)
    {
        for (int j = 0; j < index-i; j++)
        {
            if (num[j]<num[j+1])
            {
                temped=num[j];
                num[j]=num[j+1];
                num[j+1]=temped;
            }
        }
    }
    for (int i = 0; i < index; i++)
    {
        printf("%d ",num[i]);
    }
    return 0;
    
}
