#include<stdio.h>
struct TIME
{
    int id;
    int hour1;
    int min1;
    int hour2;
    int min2;
    int worktime;
};
struct TIMES{
    int id;
    int worktimes;
};
int main(){
    int n;
    scanf("%d",&n);
    struct TIME student[n];
    struct TIMES students[n];
    struct TIMES temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d:%d %d:%d",&student[i].id,&student[i].hour1,&student[i].min1,&student[i].hour2,&student[i].min2);
        student[i].worktime=60*(student[i].hour2-student[i].hour1)+(student[i].min2-student[i].min1);
        students[i].id=i+1;
        students[i].worktimes=0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (student[j].id==students[i].id)
        {
            students[i].worktimes+=student[j].worktime;
        }
        }
        
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (students[j].worktimes<students[j+1].worktimes)
            {
                temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;
            }            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if (students[i].worktimes)
        {
            printf("%d %d\n",students[i].id,students[i].worktimes);
        }
    }
    return 0;
}