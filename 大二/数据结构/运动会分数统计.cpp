#include<stdio.h>  

#define N 4
#define M 3
#define W 2
int athnum[M+W] = {7,4,6,5,6};
char school[N][20] = {"XDU","UESTC","BUPT","Harvard"};

typedef struct Athlete{
	char name[20] = {0};
	char school[20] = {0};
    int score;
    int rank;
    int project;
    int sex;
}ath;

typedef struct Project{
	int num;
    int type;
}proj;

int pick(char a[],char b[],int n) {
	int i;
	for(i = 0;i < n;i++) {
		if(a[i] != b[i]) return 0;
	}
	return 1;
}

int main() {
	int i,j,sum = 0,count = 0;
	char c; //?????
	proj a[M+W];
	ath b[100];
	int malescore[N] = {0},femalescore[N] = {0};
	for(i = 0;i < M+W;i++) {
		scanf("%d %d",&a[i].num,&a[i].type);
		for(j = 0;j < athnum[i];j++) {
			scanf("%s",b[count].name);
			c = getchar();
			gets(b[count].school);
			if(a[i].type == 5) {
				switch(j){
					case 0:
						b[count].score = 7;
						sum++;
						break;
					case 1:
						b[count].score = 5;
						sum++;
						break;
					case 2:
						b[count].score = 3;
						sum++;
						break;
					case 3:
						b[count].score = 2;
						sum++;
						break;
					case 4:
						b[count].score = 1;
						sum++;
						break;
					default:
						b[count].score = 0;
				}
			}
			else {
				switch(j){
					case 0:
						b[count].score = 5;
						sum++;
						break;
					case 1:
						b[count].score = 3;
						sum++;
						break;
					case 2:
						b[count].score = 2;
						sum++;
						break;
					default:
						b[count].score = 0;
				}
			}
			b[count].rank = j+1;
			b[count].project = a[i].num;
			if(i < M) b[count].sex = 0;
			else b[count].sex = 1;
			count++;
		}
	}
	
	for(i = 0;i < N;i++) {
		printf("\n");
		puts(school[i]);
		for(j = 0;j < count;j++) {
			if(pick(b[j].school,school[i],20) && b[j].score) {
				printf("%d %d ",b[j].project,b[j].rank);
				printf("%s",b[j].name);
			    printf(" %d\n",b[j].score);
			    if(b[j].sex == 0) malescore[i]+=b[j].score;
			    else femalescore[i]+=b[j].score;
			}
		}
		printf("Male Score:%d\nFemale Score:%d\nTotal Score:%d\n",malescore[i],femalescore[i],femalescore[i]+malescore[i]);
	}
	
	return 0;
}
