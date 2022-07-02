#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *fin=fopen("file//delete.c","r");
    FILE *fout=fopen("file//new.c","w");
    char ch;
    int row=1;
    if (fin==NULL){
        printf("No such file!");
        return 0;
    }
    fprintf(fout,"%d",row++);
    while (1){
        ch=fgetc(fin);
        if (feof(fin)!=0)
        {
            break;
        }
        if (ch=='/'){
            ch=fgetc(fin);
            if(ch=='/'){
                while(feof(fin)==0){
                    ch=fgetc(fin);
                    if (ch=='\n'){
                        fputc('\n',fout);
                        fprintf(fout,"%d",row++);
                        break;
                    }
                    
                }
            }else if (ch=='*'){
                while(feof(fin)==0){
                    ch=fgetc(fin);
                    if (ch=='*'){
                        ch=fgetc(fin);
                        if (ch=='/'){
                            break;
                        }
                    }
                }
            } 
        }else if (ch=='\n'){
            fputc(ch,fout);
            fprintf(fout,"%d",row++);
        }else{
            fputc(ch,fout);
        }
        
    }
    fclose(fin);
    fclose(fout);
    return 0;

}