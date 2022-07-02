#include<stdio.h>
#include<string.h>
int main(){
    char a[100];
    char b[100];
    gets(a);
    gets(b);
    int len1 = strlen(a);
    int len2 = strlen(b);
    int max=0;
    int num[100][100]={0};
    for(int i=0;i<len1;i++){
        if(a[i]>=65&&a[i]<=90){
            a[i]+=32;
        }
    }
    for(int i=0;i<len2;i++){
        if(b[i]>=65&&b[i]<=90){
            b[i]+=32;
        }
    }    
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j <len2;j++){
            if(a[i]==b[j]){
                if(i==0||j==0){
                    num[i][j]=1;
                }else{
                    num[i][j]=num[i-1][j-1]+1;
                    max=num[i][j]>max?num[i][j]:max;
                }
            }else num[i][j]=0;
        }
    }
    printf("%.3f",2.0*max/(len1+len2));
    return 0;
}