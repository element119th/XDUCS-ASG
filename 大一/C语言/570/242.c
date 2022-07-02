#include<stdio.h>
int main(){
    struct studenscore{
        int number;
        char name[10];
        int course[3];
        float average;
    };
    struct studenscore student[100];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int sum=0;
        scanf("%d %s",&student[i].number,student[i].name);
        for(int j=0; j<3;j++){
            scanf("%d",&student[i].course[j]);
            sum+=student[i].course[j];
        }
        student[i].average=sum/3.0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(student[j].average<student[j+1].average){
                student[n]=student[j+1];
                student[j+1]=student[j];
                student[j]=student[n];
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d %s %.1f\n",student[i].number,student[i].name,student[i].average);
    }
}