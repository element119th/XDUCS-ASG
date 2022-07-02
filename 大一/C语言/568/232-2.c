#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
 
int main() {
	char str[30],*p=str;
	int ispla;
	char *q;
	int plaindrome(char *p,char *q);
	scanf("%s",p);
	int len=strlen(p);
	q=p+len-1;
	ispla=plaindrome(p,q);
	if(ispla==1){
		printf("yes");
	}else{
		printf("no");
	} 
	
}
int plaindrome(char *p,char *q){
	int flag;
	if(p>q){
		flag=1;
	  	return flag;
	}	
	 if(*p==*q){
		p++;
		q--;
		plaindrome(p,q);
	   }else{
	    flag=0; 
		return flag;
	   } 
}