#include <stdio.h>
#include <string.h>
int main() {
	int score = 0, len;
	int num=0,alph=0,Alph=0,ec=0;
	char pw[50];
	gets(pw);
	len = strlen(pw);
	if(pw[0]==' '){
		printf("0");
		return 0;
	}else score=1;
	if(len>8){
		score++;
	}
	for(int i=0;i<len;i++){
		if(pw[i]<=57&&pw[i]>=48)
		   num=1;
		else if(pw[i]<=90&&pw[i]>=65)
		   Alph=1;
		else if(pw[i]<=122&&pw[i]>=97)
		   alph=1;
		else ec=1;		   
	}
	
	printf("%d", num+Alph+alph+ec-1+score);
	return 0;
}
