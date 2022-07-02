#include <stdio.h>
#include <string.h>
int main(){
    char a[150][150];
    char cmp[10]="***end***";
    int counter[100]={0};
    int i=0,x=0;
    int lenmax=0,len=0;
    while(1){
        gets(a[i]);
        if(!strcmp(a[i], cmp)){
            break;
        }
        len=strlen(a[i]);
        if(len>lenmax){
            lenmax=len;
            x=i;
            counter[lenmax]++;
        }
        i++;
    }
    for(int i=100; i>0;i--){
        if(counter[i]==2){
            puts(a[0]);
            break;
        }else if(counter[i]==1){
            printf("%d\n",lenmax);
            puts(a[x]);
            break;
        }
    }
    return 0;
}