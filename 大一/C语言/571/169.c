#include<stdio.h>
#include<string.h>
struct FILE{
    char date[11];
    int size;
};
int main(){
    int n;
    scanf("%d",&n);
    struct FILE data[n+1],temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%s",&data[i].date);
        scanf("%d",&data[i].size);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (strcmp(data[j].date,data[j+1].date)<0)
            {
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;

            }
                if (strcmp(data[j].date,data[j+1].date)==0 && data[j].size<data[j+1].size)
            {
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;          
            }            
            
        }
        
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d",data[i].date,data[i].size);
        printf("\n");
    }
    
    return 0;
}