#include<stdio.h>
int main(){
    int bord[50][50]={0};
    char base[50][50]={0};
    int m,n,start;
    scanf("%d %d %d",&n,&m,&start);
    int x=start,y=1;
    for(int i=1;i<=n;i++){
        getchar();
        for(int j=1;j<=m;j++){
            scanf("%c",&base[i][j]);
        }
    }
    bord[1][start]=1;
    int loop=0;
    int flag=0;
    while(base[y][x]!=0){
        if(base[y][x]=='W'){
            x-=1;
        }else if(base[y][x]=='E'){
            x+=1;
        }else if(base[y][x]=='N'){
            y-=1;
        }else{
            y+=1;
        }
        if(bord[y][x]==1){
            flag=1;
            break;
        }
        bord[y][x]=1;
        loop++;
    }
    if(flag==1){
        printf("loop %d",loop+1);
    }else{
        printf("out %d",loop);
    }
    return 0;
}