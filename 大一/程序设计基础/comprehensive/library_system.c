#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book{
    int number;
    char name[30];
    int amount;
}Book;
struct reader{
    int id;
    char name[20];
    char borrowedBook[30];
    //flag=1则说明在借书状态；
    int flag;
}Reader;
int adminOperate();
int adminOperateB();
int adminOperateR();
int readerOperate();
int bookBorrow();
int bookReturn();
void whoBorrowBook();
int searchBook();
int readerMatch();
int bookAdd();
int bookRevise();
int bookDelete();
int readerAdd();
int readerRevise();
int readerDelete();
int main(){
    int choice;
    printf("请选择您的身份:\n1.管理员\n2.读者\n");
    scanf("%d",&choice);
    if (choice==1)
    {
        char passward[20];
        printf("请输入管理员密码:");
        scanf("%s",passward);
        if (strcmp(passward,"114514")==0)
        {
            printf("欢迎您,管理员！\n");
            if(adminOperate()==0){
                return 0;
            }
        }else{
            printf("密码错误！");
            return 0;
        }
    }
    else if(choice==2){
        if(readerMatch()==1){
            readerOperate();
        }else{
            return 0;
        }
    }
}
//读者匹配
int readerMatch(){
    FILE *reader = fopen("file//readers.txt","r");
    int id,sign=0;
    char name[20];
    printf("请输入您的编号和姓名,中间用空格隔开!\n");
    scanf("%d %s",&id,name);
    while (feof(reader)==0)
    {
        fscanf(reader,"%d%20s%10d%30s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
        if (id==Reader.id&&(strcmp(name,Reader.name)==0))
        {
            printf("您的信息为:\n编号:%d\n姓名%s\n",id,name);
            sign=1;
            fclose(reader);
            return 1;
        }
    }
    if (sign==0)
    {
        printf("系统中未查询到您的信息,请联系图书馆管理员录入信息!\n");
        fclose(reader);
        return 0;
    }
    return 0;
}
//查询书籍
int searchBook(){
    FILE *book = fopen("file//books.txt","r");
    FILE *reader = fopen("file//books.txt","r");
    if (book==NULL||reader==NULL)
    {
        printf("数据异常！");
    }
    int choice,flag=0;
    printf("请选择查询方式：\n1.编号\n2.书名\n");
    scanf("%d",&choice);
    if (choice==1)
    {
        int num;
        printf("请输入书的编号：\n");
        scanf("%d",&num);
        while (feof(book)==0)
        {
            fscanf(book,"%d%20s%10d\n",&Book.number,Book.name,&Book.amount);
            if (num==Book.number)
            {
                flag=1;
                printf("编号:%d\n书名:%s\n数量:%d\n",Book.number,Book.name,Book.amount);
            }
            if (flag==1){
                break;
            }
        }
        
    }else if(choice==2){
        char name[30];
        printf("请输入书的名称：\n");
        scanf("%s",name);
        while (feof(book)==0)
        {
            fscanf(book,"%d%20s%10d\n",&Book.number,Book.name,&Book.amount);
            if (strcmp(name,Book.name)==0)
            {
                flag=1;
                printf("编号:%d\n书名:%s\n数量:%d\n",Book.number,Book.name,Book.amount);
                break;
            }
        }
    }
    fclose(book);
    fclose(reader);
    if (flag==0){
        printf("对不起,暂无该书籍信息!您可以联系图书馆管理员购入!\n");
        return 0;
    }
    return 1;
}
//读者操作
int readerOperate(){
    int choice;
    printf("请选择您要进行的操作:\n1.借阅图书\n2.归还图书\n");
    scanf("%d",&choice);
    if(choice==1){
        bookBorrow();
    }else if(choice==2){
        bookReturn();
    }else{
        printf("您输入的指令有误,请重新输入!");
        readerOperate();
    }
    return 0;
}
//读者借书操作
int bookBorrow(){
    if (Reader.flag==1){
    printf("对不起,每人仅限借阅一本书!\n您当前借阅书籍信息:\n");
    printf("书籍名称:%s\n",Reader.borrowedBook);
    printf("请归还后再借阅!");
    }else{
        printf("请查找要借阅的书籍：\n");
        if (searchBook()==1)
        {
            if (Book.amount<1)
            {
                printf("这本书已全部借出！\n");
            }else{
                int tempreader = Reader.id;
                char booked[30];
                int tempbook = Book.number;
                strcpy(booked,Book.name);
                FILE *reader1 = fopen("file//readers.txt","r");
                FILE *reader2 = fopen("file//readers2.txt","w");
                FILE *book1 = fopen("file//books.txt","r");
                FILE *book2 = fopen("file//books2.txt","w");
                while (feof(book1)==0)
                {
                    fscanf(book1,"%d%s%d\n",&Book.number,Book.name,&Book.amount);
                    if (Book.number!=tempbook){
                        fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount);
                    }else{
                        fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount-1);
                    }
                }
                while (feof(reader1)==0)
                {
                    fscanf(reader1,"%d%s%d%s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
                    if (Reader.id!=tempreader){
                        fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,Reader.flag,Reader.borrowedBook);
                    }else{
                        fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,1,booked);
                    }                    
                }
                printf("借阅成功！");
                fclose(reader2);
                fclose(reader1);
                fclose(book2);
                fclose(book1);
                remove("file//books.txt");
                remove("file//readers.txt");
                rename("file//readers2.txt","file//readers.txt");
                rename("file//books2.txt","file//books.txt");
            }
            
        }else{
            bookBorrow();
        }
        
    }
    return 0;
}
//读者还书操作
int bookReturn(){
    if (Reader.flag==0){
        printf("您当前未借阅图书,无须归还。\n");
        return 0;
        }else{
                int tempreader = Reader.id;
                char tempbook[30];
                strcpy(tempbook,Reader.borrowedBook);
                FILE *reader1 = fopen("file//readers.txt","r");
                FILE *reader2 = fopen("file//readers2.txt","w");
                FILE *book1 = fopen("file//books.txt","r");
                FILE *book2 = fopen("file//books2.txt","w");
                while (feof(book1)==0)
                {
                    fscanf(book1,"%d%30s%10d\n",&Book.number,Book.name,&Book.amount);
                    if (strcmp(tempbook,Book.name)==0){
                        fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount+1);
                    }else{
                        fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount);
                    }
                }
                while (feof(reader1)==0)
                {
                    fscanf(reader1,"%d%20s%10d%30s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
                    if (tempreader!=Reader.id){
                        fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,Reader.flag,Reader.borrowedBook);
                    }else{
                        fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,0,"0");
                    }                    
                }
                printf("还书成功！");
                fclose(reader2);
                fclose(reader1);
                fclose(book2);
                fclose(book1);
                remove("file//books.txt");
                remove("file//readers.txt");
                rename("file//readers2.txt","file//readers.txt");
                rename("file//books2.txt","file//books.txt");
                return 1;
    }
}
//管理员操作选项
int adminOperate(){
    int choice;
    printf("请选择您要进行操作的对象:\n1.图书\n2.读者\n3.退出\n");
    scanf("%d",&choice);
    if(choice==1){
        adminOperateB();
    }else if(choice==2){
        adminOperateR();
    }else if(choice==3){
        printf("已成功退出！");
        return 0;
    }else{
        printf("您输入的指令有误,请重新输入!\n");
        adminOperate();
    }
    return 0;
}
//管理员对书籍的操作
int adminOperateB(){
    int choice;
    printf("请选择您接下来要进行的操作:\n1.录入图书信息;\n2.修改图书信息;\n3.删除图书信息;\n4.查询借书人;\n5.返回上一步\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        bookAdd();
        break;
    case 2:
        bookRevise();
        break;
    case 3:
        bookDelete();
        break;
    case 4:
        whoBorrowBook();
        break;
    case 5:
        adminOperate();
        break;
    default:
        printf("您输入的指令有误,请重新输入!\n");
        break;
    }
    return 0;
}
//管理员对读者信息的操作
int adminOperateR(){
    int choice1;
    printf("请选择您接下来要进行的操作:\n1.录入读者信息;\n2.修改读者信息;\n3.删除读者信息;\n4.返回\n");
    scanf("%d",&choice1);
    switch (choice1)
    {
    case 1:
        readerAdd();
        break;
    case 2:
        readerRevise();
        break;
    case 3:
        readerDelete();
        break;
    case 4:
        adminOperate();
        break;
    default:
        printf("您输入的指令有误,请重新输入!");
        adminOperateR();
        break;
    }
    return 0;
}
int bookAdd(){
    int tempnum,tempamount;
    char tempname[30];
    FILE *book = fopen("file//books.txt","r+");
    printf("请输入需要录入书籍的信息：\n(格式:编号 名称 数量)\n");
    scanf("%d %s %d",&tempnum,tempname,&tempamount);
    while (feof(book)==0)
        fscanf(book,"%d %s %d\n",&Book.number,Book.name,&Book.amount);
    fprintf(book,"%d%30s%10d\n",tempnum,tempname,tempamount);
    printf("录入成功！\n");
    fclose(book);
    return 0;
}
int bookRevise(){
    int id;
    int tempid,tempamount;
    char tempname[30];
    printf("请输入需要修改书籍的编号：\n");
    scanf("%d",&id);
    printf("请输入修改后书籍的信息：\n(格式:编号 名称 数量)\n");
    scanf("%d %s %d",&tempid,tempname,&tempamount);
    FILE *book1 = fopen("file//books.txt","r");
    FILE *book2 = fopen("file//books2.txt","w");
    while (!feof(book1))
    {
        fscanf(book1,"%d%30s%10d\n",&Book.number,Book.name,&Book.amount);
        if (Book.number==id){
            fprintf(book2,"%d%30s%10d\n",tempid,tempname,tempamount);
        }else{
            fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount);
        }
    }
    printf("修改成功！\n");               
    fclose(book2);
    fclose(book1);
    remove("file//books.txt");
    rename("file//books2.txt","file//books.txt");          
    return 0;
}
int bookDelete(){
    int id;
    printf("请输入需要删除书籍的编号：\n");
    scanf("%d",&id);
    FILE *book1 = fopen("file//books.txt","r");
    FILE *book2 = fopen("file//books2.txt","w");
    while (feof(book1)==0)
    {
        fscanf(book1,"%d%30s%10d\n",&Book.number,Book.name,&Book.amount);
        if (Book.number!=id){
            fprintf(book2,"%d%30s%10d\n",Book.number,Book.name,Book.amount);
        }else{
            continue;
        }
    }
    printf("删除成功！\n");               
    fclose(book2);
    fclose(book1);
    remove("file//books.txt");
    rename("file//books2.txt","file//books.txt");  
    return 0;
}
int readerAdd(){
    int tempid;
    char tempname[20];
    FILE *reader = fopen("file//readers.txt","r+");
    printf("请输入需要录入读者的信息：\n(格式:编号 名称)\n");
    scanf("%d %s",&tempid,tempname);
    while (feof(reader)==0)
        fscanf(reader,"%d %s %d %s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
    fprintf(reader,"%d%20s%10d%30s\n",tempid,tempname,0,"0");
    printf("录入成功！\n");
    fclose(reader);
    return 0;
}
int readerRevise(){
    int id;
    int tempid;
    char readername[20];
    char tempname[30];
    printf("请输入需要修改读者的编号\n");
    scanf("%d",&id);
    printf("请输入修改后读者的信息：\n(格式:编号 姓名)\n");
    scanf("%d %s",&tempid,readername);
    strcpy(tempname,"0");
    FILE *reader1 = fopen("file//readers.txt","r");
    FILE *reader2 = fopen("file//readers2.txt","w");
    while (feof(reader1)==0)
    {
        fscanf(reader1,"%d%s%d%s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
        if (id!=Reader.id){
            fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,Reader.flag,Reader.borrowedBook);
        }else{
            fprintf(reader2,"%d%20s%10d%30s\n",tempid,readername,Reader.flag,Reader.borrowedBook);
        }                    
    }
    printf("修改成功！\n");
    fclose(reader2);
    fclose(reader1);                
    remove("file//readers.txt");
    rename("file//readers2.txt","file//readers.txt");
    return 0;
}
int readerDelete(){
    int id;
    printf("请输入需要删除读者的编号：\n");
    scanf("%d",&id);
    FILE *reader1 = fopen("file//readers.txt","r");
    FILE *reader2 = fopen("file//readers2.txt","w");
    while (feof(reader1)==0)
    {
        fscanf(reader1,"%d%s%d%s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
        if (id!=Reader.id){
            fprintf(reader2,"%d%20s%10d%30s\n",Reader.id,Reader.name,Reader.flag,Reader.borrowedBook);
        }else{
            continue;
        }                    
    }
    printf("删除成功！\n");
    fclose(reader2);
    fclose(reader1);                
    remove("file//readers.txt");
    rename("file//readers2.txt","file//readers.txt");
    return 0;
}
void whoBorrowBook(){
    char book[30];
    printf("请输入书籍名称：");
    scanf("%s",book);
    printf("这些人借阅了这本书：\n");
    FILE *reader = fopen("file//readers.txt","r");
    while(!feof(reader))
    {
        fscanf(reader,"%d%20s%d%30s\n",&Reader.id,Reader.name,&Reader.flag,Reader.borrowedBook);
        if(strcmp(Reader.borrowedBook,book)==0)
        {
            printf("%d%20s\n",Reader.id,Reader.name);
        }
    }
    fclose(reader);
}
