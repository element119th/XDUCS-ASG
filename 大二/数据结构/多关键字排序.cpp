#include<stdio.h>
#include<string.h>

typedef struct Stu {
	int grade;
	int age;
	char name[30];
}St;

void AgeSort(St *a,int r[],int m,int n) {
	int i,j;
	for(i = m;i <= n;i++) {
		for(j = i+1;j <= n;j++) {
			if(a[r[i]].age > a[r[j]].age) {
				int temp = r[i];
				r[i] = r[j];
				r[j] = temp;
			}
		}
	}
}

void NameSort(St *a,int r[],int m,int n) {
	int i,j;
	for(i = m;i <= n;i++) {
		for(j = i+1;j <= n;j++) {
			if(strcmp(a[r[i]].name,a[r[j]].name) > 0) {
				int temp = r[i];
				r[i] = r[j];
				r[j] = temp;
			}
		}
	}
	for(i = m;i <= n-1;i++) {
		if(strcmp(a[r[i]].name,a[r[i+1]].name) == 0) {
			int s = i;
			while(i <= n-1 && strcmp(a[r[i]].name,a[r[i+1]].name) == 0) i++;
			AgeSort(a,r,s,i);
		}
	}
}

void GradeSort(St *a,int r[],int n) {
	int i,j,temp,max;
	for(i = 0;i < n;i++) {
		max = i;
		for(j = i+1;j < n;j++) 
			if(a[r[j]].grade > a[r[max]].grade) max = j;
		temp = r[i];
		r[i] = r[max];
		r[max] = temp;
	}
	for(i = 0;i < n-1;i++) {
		if(a[r[i]].grade == a[r[i+1]].grade) {
			int s = i;
			while(i < n-1 && a[r[i+1]].grade == a[r[i]].grade) i++;
			NameSort(a,r,s,i);
		}
	}
}

int main() {
	int i,n,r[100];
	St a[100];
	scanf("%d",&n);
	for(i = 0;i < n;i++) {
		scanf("%s",a[i].name);
		scanf("%d %d",&a[i].age,&a[i].grade);
		r[i] = i;
	}
	GradeSort(a,r,n);
	for(i = 0;i < n;i++) {
		printf("%s",a[r[i]].name);
		printf(" %d %d\n",a[r[i]].age,a[r[i]].grade);
	}
	
	return 0;
}
