#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXSIZE 50

typedef struct  {       //Huffman树的定义
	char name;
	unsigned int w;    //权值
	unsigned int pa;   //父节点
	unsigned int lch;   //左子树
	unsigned int rch;   //右子树
} HTnode;

typedef struct {   //Huffman编码
	int data;
	char name1;
	char *pre;
} HCnode;

int N,M;
HCnode *HC;
HTnode *HT;

void Reverse(char *str) {    //字符串倒置，如此便不需要反向编码
	int i,j;
	char ch;
	for(i=0,j=strlen(str)-1; i<j; i++,j--) {
		ch=str[i];
		str[i]=str[j];
		str[j]=ch;
	}
}

int min_node(HTnode *HT,int n) { //寻找Node中最小的节点
	int i,min;
	for(i=1; HT[i].pa; i++); //寻找根节点
	min=i;
	for(i=1; i<n; i++)
		if(!HT[i].pa)
			if(HT[i].w<HT[min].w)
				min=i;
	HT[min].pa=1;
	return min;
}

void Output_HT(HTnode *HT) { //输出Huffman树
	int i;
	printf(" 编号  名称 权值 父节点 左子树 右子树\n");
	for(i=1; i<2*N; i++) {
		printf(" |%-5d %c    %-5d %-5d %-6d %-4d|\n",i,
		       HT[i].name,HT[i].w,  
		       HT[i].pa,HT[i].lch,
		       HT[i].rch);
	}
}

void PrintHC(HCnode *HC) {    //输出Huffman编码
	FILE *f1,*f2;
	int i=0,j=0,x=0,n=0,wpl=0;      //wpl带权路径长度
	char temp[50];
	if((f1=fopen("ToBeTran.txt","r"))==NULL) {     //打开ToBeTran.txt
		printf("open failed!\n");
		exit(0);
	}
	if((f2=fopen("Code.txt","w"))==NULL) {      //打开Code.txt
		printf("open failed!\n");
		exit(0);
	}
	printf("输出Huffman编码\n");
	for(i=1; i<=N; i++)  {
		printf("%c-->%s",HC[i].name1,HC[i].pre);
		x=strlen(HC[i].pre);
		wpl+=(HC[i].data*x);
		printf("\n");
	}
	i=0;
	while(!feof(f1)) { //从ToBeTran中读取字符并写入Code
		temp[i]=fgetc(f1);
		for(j=1; j<=N; j++)
			if(temp[i]==HC[j].name1) {
				fprintf(f2,"%s",HC[j].pre);
			}
		i++;
	}
	fprintf(f2,"\b");
	fclose(f1);
	fclose(f2);
}

HTnode *Create() {               //构造Huffman树
	FILE *fp;
	int i,Si,Sj;                //找出来的两个最小子树保存在Si和Sj里面
	HTnode *HT;
	HT=(HTnode *)malloc((2*N)*sizeof(HTnode));             //给HT分配2N-1这里分配2N个
	if((fp=fopen("DataFile.txt","rt"))==NULL) {           //读取DataFile的文件
		printf("can not find file DataFile failed!\n");
		exit(0);
	}
	for(i=1; i<=N; i++) {
		fscanf(fp,"%c,%d",&HT[i].name,&HT[i].w);            //将Data的名称和权值赋值给HT
		HT[i].lch=HT[i].rch=HT[i].pa=0;                     //初始化
	}
	printf("\n");
	for(; i<=M; i++)
		HT[i].lch=HT[i].rch=HT[i].pa=HT[i].w=0;            //对其它多余的树进行初始化
	for(i=N+1; i<=M; i++) {
		Si=min_node(HT,i);            //寻找最小的节点
		Sj=min_node(HT,i);
		HT[i].w=HT[Si].w+HT[Sj].w;           //创建
		HT[Si].pa=HT[Sj].pa=i;
		HT[i].lch=Si;
		HT[i].rch=Sj;
	}
	
	return HT;
}

HCnode *Coding(HTnode *HT) {                     //Huffman编码
	int i,j,c,f;
	HCnode *HC;
	char data[MAXSIZE];
	HC=(HCnode *)malloc(N*sizeof(HCnode));                  //叶子节点的个数
	for(i=1; i<=N; i++) {
		memset(data,'\0',MAXSIZE);
		HC[i].name1=HT[i].name;                      //将树的名称给HC
		HC[i].data=HT[i].w;                         //权值复制
		for(c=i,j=0,f=HT[c].pa; f; c=f,f=HT[f].pa,j++) {          //根节点循环终止，HC[f]的父节点给f，反向Huffman编码
			if(HT[f].lch==c) data[j]='0';           //左子树为0，右子树为1
			else data[j]='1';
		}
		HC[i].pre=(char *)malloc((strlen(data)+1)*sizeof(char));
		Reverse(data);                     //逆置Huffman编码
		for(j=0; j<strlen(data)+1; j++)
			HC[i].pre[j]=data[j];
		HC[i].pre[j]='\0';                //将Huffman编码给HC.pre[]
	}
	return HC;
}

void Decoding(HTnode *HT) {         //解码
	FILE *fp1,*fp2;
	char ch[50];
	char cod[200];
	int f,root,i=0,j=0;
	if((fp1=fopen("CodeFile.txt","r"))==NULL) {
		printf("open file failed");
		exit(0);
	}
	if((fp2=fopen("Textfile.txt","w"))==NULL) {
		printf("open file failed");
		exit(0);
	}
	while(!feof(fp1)) {             //将Codefile的文件给cod[]
		fscanf(fp1,"%c",&cod[i]);
		i++;
	}
	i=1;
	while(HT[i].pa) {
		i++;                //寻找根节点
	}
	root=i;
	i=0;
	while(cod[i]!='\b') {             //结尾
		f=root;
		while(HT[f].lch!=NULL) {             //不为空
			if(cod[i]=='0') f=HT[f].lch;
			else f=HT[f].rch;
			i++;
		}
		ch[j++]=HT[f].name;
	}
	ch[j]='\0';
	printf("\nCodeFile.txt解码为:%s\n",ch);
	i=0;
	fprintf(fp2,"%s\b",ch);
	fclose(fp1);
	fclose(fp2);
}

void Output() {          //输出Textfile.txt、ToBeTran.txt、Code.txt、CodeFile.txt、Textfile.txt
	int c;
	char b;
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	if((fp1=fopen("Datafile.txt","r"))==NULL) {
		printf("open file0 failed!\n");
		exit(0);
	}
	if((fp1=fopen("Datafile.txt","r"))==NULL) {
		printf("open file0 failed!\n");
		exit(0);
	}
	if((fp2=fopen("ToBeTran.txt","r"))==NULL) {
		printf("open file ToBeTran failed!\n");
		exit(0);
	}
	if((fp3=fopen("Code.txt","r"))==NULL) {
		printf("open file Code failed!\n");
		exit(0);
	}
	if((fp4=fopen("CodeFile.txt","r"))==NULL) {
		printf("open file CodeFile failed!\n");
		exit(0);
	}
	if((fp5=fopen("Textfile.txt","r"))==NULL) {
		printf("open file Textfile failed!\n");
		exit(0);
	}
	printf("\n输出DataFlie中的字符及其权值:\n");
	while(!feof(fp1)) {
		fscanf(fp1,"%c,%d", &b,&c);
		printf("'%c'---%d\n",b,c);
	}
	printf("\n\n输出ToBeTran:\n");
	while(!feof(fp2)) {
		fscanf(fp2,"%c",&b);
		printf("%c",b);
	}
	printf("\n\n输出Code.txt:\n");
	while(!feof(fp3)) {
		fscanf(fp3,"%c",&b);
		printf("%c",b);
	}
	printf("\n\n输出CodeFile.txt:\n");
	while(!feof(fp4)) {
		fscanf(fp4,"%c",&b);
		printf("%c",b);
	}
	printf("\n\n输出Textfile.txt:\n");
	while(!feof(fp5)) {
		fscanf(fp5,"%c",&b);
		printf("%c",b);
	}
	printf("\n");
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
}

void Output2(int n) {            //输出Textfile.txt、ToBeTran.txt、Code.txt、CodeFile.txt、Textfile.txt
	int c;
	char b;
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	switch(n) {
		case 2:
			printf("\n输出ToBeTran:\n");
			if((fp2=fopen("ToBeTran.txt","r"))==NULL) {
				printf("open file ToBeTran failed!\n");
				exit(0);
			}
			while(!feof(fp2)) {
				fscanf(fp2,"%c",&b);
				printf("%c",b);
			}
			fclose(fp2);
			break;
		case 3:
			printf("\n\n输出Code.txt:\n");
			if((fp3=fopen("Code.txt","r"))==NULL) {
				printf("open file Code failed!\n");
				exit(0);
			}
			while(!feof(fp3)) {
				fscanf(fp3,"%c",&b);
				printf("%c",b);
			}
			fclose(fp3);
			break;
		default:
			printf("ERROR!");
	}
	printf("\n");
}        

int main() {
	int i;
	char c;
	FILE *fp;
	char **code;   //构建一个二维数组解码用
	char ope;
	printf("根据Data文件请输入叶节点个数 : ");
	scanf("%d",&N);
	printf("请输入所要进行的操作："); 
	c = getchar();
	c = getchar();
	while(c != 'Q') {
		if(N>0&&N<=500) {
			M=2*N-1;
			code=(char**)malloc(100*sizeof(char));
			for(i=0; i<N; i++)
				code[i]=(char *)malloc(8*sizeof(char));
			HT=Create();
			if(c == 'T') Output_HT(HT);
			if(c == 'E') {
				printf("对Huffman树进行编码:\n");
				HC=Coding(HT);
				PrintHC(HC);
				printf("-------------------------------------------------------------------\n");
				printf("将ToBeTran的内容改写成编码写入Code.txt\n");
				Output2(3);
			}
			if(c == 'D') {
				Output2(2);
				printf("-------------------------------------------------------------------\n");
				printf("对文件CodeFile.data中的代码进行解码形成原文，结果存入文件Textfile.txt中\n");
		    }
			printf("\n请输入所要进行的操作："); 
	        c = getchar();
	        c = getchar();
		} 
		else printf("请重新输入:\n");
	}
	
	return 0;
}
