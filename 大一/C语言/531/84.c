#include<stdio.h>
#include<string.h>
int main(){
    char path[200]={0};
    char cmd[20][60]={'\0'};
    gets(path);
    int i=0;
    while (1)
    {
        gets(cmd[i]);
        if (!strcmp(cmd[i],"pwd")){
            break;
        }
        i++;
    }
    for (int j=0; j<i;j++){
        char *p;
        if(cmd[j][3]=='/'){
            if(cmd[j][4]=='0'){
                strcpy(path,"/");
            }else{
                p=&cmd[j][3];
                strcpy(path,p);
            }
        }else{
            int len=strlen(path);
            if(cmd[j][3]=='.'&&cmd[j][4]=='.'){
                if(len!=1){
                    int i=len;
                    while(path[i]!='/'){
                        path[i]=0;
                        i--;
                    }
                    path[i]=0;
                    if(strlen(path)==0){
                        path[0]='/';
                    }
                }
            }else{
                p=&cmd[j][3];
                if(path[len-1]!='/'){
                    path[len]='/';
                }
                strcat(path,p);
            }
        }
    }
    puts(path);
    return 0;
}