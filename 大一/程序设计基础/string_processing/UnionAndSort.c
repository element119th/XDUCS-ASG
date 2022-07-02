#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fin1=fopen("file\\num1.txt","rt");
    FILE *fin2=fopen("file\\num2.txt","rt");
    FILE *fout1=fopen("file\\num3.txt","wt");
    if(fin1==NULL||fin2==NULL){
        printf("No such file!");
        return 0;
    }
    int num[100]={0};
    int n=0,temp=0;
    while (feof(fin1)==0)
    {
        fscanf(fin1,"%d",&num[n++]);
        
    }
    while (feof(fin2)==0)
    {
        fscanf(fin2,"%d",&num[n++]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fout1,"%d ",num[i]);
    }
    fclose(fin1);
    fclose(fin2);
    fclose(fout1);
    return 0;
}