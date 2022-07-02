#include<stdio.h>
#include<stdlib.h>

struct windows{
        int loc[4];
    };
int ISINSIDE(int x,int y,struct windows p){
    if(x<p.loc[0]) return 0;
    if(x>p.loc[2]) return 0;
    if(y<p.loc[1]) return 0;
    if(y>p.loc[3]) return 0;    
    return 1;
}
int main(){
    int n,m;
    int reslut[50]={0};
    scanf("%d %d",&n,&m);
    struct  windows winnum[11];
    for(int i=0;i<n;i++){
        for (int j = 0; j < 4; j++)
        {
            scanf("%d",&winnum[i].loc[j]);
        }
    }
    int x,y;
    int num=-1;
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        for(int j=n-1;j>=0;j--){
            if(ISINSIDE(x,y,winnum[j])){
                reslut[num++]=j;
            }
        }
    }
    return 0;
}