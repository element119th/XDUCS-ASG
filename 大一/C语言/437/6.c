  #include<stdio.h>
int weishu(int a){
    int sum=0;
    while (a)
    {
       sum++;
    }
    return sum;  
}
int main(){
    int n,x,y;
    int a[1000];
    int b[1000];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        b[i]=weishu(a[i]);
    }
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (b[j]>b[j+1])
            {
                x=b[j];
                b[j]=b[j+1];
                b[j+1]=x;
                y=a[j];
                a[j]=a[j+1];
                a[j+1]=y;                
            }
            if (b[j]=b[j+1])
            {   if (a[j]>a[j+1])
            {
                x=b[j];
                b[j]=b[j+1];
                b[j+1]=x;
                y=a[j];
                a[j]=a[j+1];
                a[j+1]=y;                
            }                
            }           
        }
        
    }*/
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n",a[i],b[i]);
    }
    return 0;
}