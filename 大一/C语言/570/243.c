#include<stdio.h>
int main(){
    struct student_data{
        char name[20];
        int score[6];
        int total;
    };
    struct student_data stu[100];
    int n ;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%s",stu[i].name);
        stu[i].total=0;
        for(int j=0; j<6;j++){
            scanf("%d",&stu[i].score[j]);
            stu[i].total+=stu[i].score[j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(stu[j].total<stu[j+1].total){
                stu[n]=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=stu[n];
            }else if(stu[j].total==stu[j+1].total){
                if(stu[j].score[5]<stu[j+1].score[5]){
                    stu[n]=stu[j];
                    stu[j]=stu[j+1];
                    stu[j+1]=stu[n];       
                }         
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%s %d %d\n",stu[i].name,stu[i].total,stu[i].score[5]);
    }
    return 0;
}