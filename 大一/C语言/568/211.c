#include<stdio.h>
void aver(double (*p)[4]){
    double average=0;
    double sum=0;
    for(int i=0; i<5;i++){
        sum+=**(p+i);
    }
    average=sum/5;
    printf("%.1lf ",average);
}
void fals(double *p){
    int total=0;
    for(int i=0; i<5;i++){
        int sum=0;
        for(int j=0; j<4;j++){
            if(*(p+i*4+j)<60){
                sum++;
            }
        }
        if(sum>=2){
            total++;
        }
    }
    printf("%d ",total);
}

void well(double *p){
    int total=0;
    for(int i=0; i<5;i++){
        int totmro=0,sum=0;
        for(int j=0; j<4;j++){
            sum+=*(p+i*4+j);
            if(*(p+i*4+j)>=85){
                totmro++;
            }
        }
        if((sum/4.0)>=90 || totmro==4){
            total++;
        }
    }
    printf("%d",total);
}
int main(){
    double stu[5][4]={0};
    double *q=stu;
    for(int i=0;i<20;i++){
        scanf("%lf",q+i);
    }
    aver(stu);
    fals(stu);
    well(stu);
    return 0;
}