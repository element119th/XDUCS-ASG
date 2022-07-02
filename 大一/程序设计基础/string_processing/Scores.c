#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct scores
{
    char name[20];
    int english;
    int math;
    float average;
        
};
int main(){
    FILE *fin1=fopen("file\\db1.txt","rt");
    FILE *fin2=fopen("file\\db2.txt","rt");
    FILE *fout1=fopen("file\\db3.txt","wt");
    if(fin1==NULL||fin2==NULL){
        printf("No such file!");
        return 0;
    }
    struct scores englishscore[50],mathscore[50],allscore[50];
    int n1=0,n2=0,n3=0;
    while (feof(fin1)==0)
    {
       fscanf(fin1,"%s",&englishscore[n1].name);
       fscanf(fin1,"%d",&englishscore[n1].english);
       n1++;
    }
        while (feof(fin2)==0)
    {
       fscanf(fin2,"%s",&mathscore[n2].name);
       fscanf(fin2,"%d",&mathscore[n2].math);
       n2++;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (strcmp(englishscore[i].name,mathscore[j].name)==0)
            {
                strcpy(allscore[n3].name,englishscore[i].name);
                allscore[n3].english=englishscore[i].english;
                allscore[n3].math=mathscore[j].math;
                allscore[n3].average=(allscore[n3].english+allscore[n3].math)/2.0;
                n3++;
            }
        }  
    }
    for (int i = 0; i < n3; i++)
    {
        fprintf(fout1,"%s %d %d %.1f\n",allscore[i].name,allscore[i].english,allscore[i].math,allscore[i].average);
    }
    fclose(fin1);
    fclose(fin2);
    fclose(fout1);
    return 0;
}