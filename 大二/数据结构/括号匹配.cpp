#include<stdio.h>

int deepin(char a[],int n) {
	int i,max = 0,temp = 0;
	for(i = 0;i < n;i++) {
		if(a[i] == '[' || a[i] == '(' ) temp++;
		else temp--;
		if(temp > max) max = temp;
	}
	return max;
}

int find(char a[],int n,int deep) {
	int i,temp = 0,num = 0,temp2,j;
	for(i = 0;i < n;i++) {
		if(a[i] == '[' || a[i] == '(' ) temp++;
		else temp--;
		if(temp == deep) {
			temp2 = temp;
			for(j = i+1;j < n;j++) {
				if(((a[i] == '[' && a[j] == ']') || (a[i] == '(' && a[j] == ')')) && temp == temp2) {
					num+=2;
					break;
				}
				if(a[j] == '[' || a[j] == '(' ) temp2++;
		        else temp2--;
			}
		}
	}
	return num;
}

int main() {
	int i,j = 0,k = 0,p = 0,result[5] = {0},n,max,temp = 0;
	char a[5][1000],c;
	scanf("%d",&n);
	c = getchar();
	for(i = 0;i < n;i++) {
		while(a[i][p] = getchar()) {
			if(a[i][p] != '[' && a[i][p] != '(' && a[i][p] != ']' && a[i][p] != ')') break;
			p++;
		}
		if(p % 2 != 0) result[i] = 0;
		max = deepin(a[i],p);
		for(j = max;j >= 1;j--) temp += find(a[i],p,j);
		if(temp == p) result[i] = 1;
		p = 0;
		max = 0;
		temp = 0;
	}
	for(i = 0;i < n;i++) {
		if(result[i] == 0) printf("No\n");
	    else printf("Yes\n");
	}	
	return 0;
} 
