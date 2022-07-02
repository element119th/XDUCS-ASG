#include<stdio.h>
int main(){
	int seats[20][5]={0};
	int cmd;
	int cmds[100];
	scanf("%d",&cmd);
	for(int i=0;i<cmd;i++){
		scanf("%d",&cmds[i]);
	}
	for(int i=0;i<cmd;i++){
		for(int j =0;j<20;j++){
			int st=0,end=0,flag=0;
			for(int k=0;k<5;k++){
				if(seats[j][k]==0){
					st=k;
					while(seats[j][k]==0){
						end = k;
						k++;
					}
					if(cmds[i]<=end-st){
						for(int l=0;l<cmds[i];l++){
							seats[j][st+l]=1;
						}
                        flag = 1;
                        break;
					}
				}
			}
            if (flag==1)
            {
                break;
            }
            
		}
	}
	for(int i=0;i<20;i++){
		for(int j=0;j<5;j++){
			if(seats[i][j]==1){
				printf("%d ",i*5+j+1);
			}
		}
        printf("\n");
	}
	return 0;
}