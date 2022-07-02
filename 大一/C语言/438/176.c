#include <stdio.h>
int main(){
    int n=0;
    int temp=0;
    int a[1000];
    int x=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    if(n%2){
        int total=0;
        x=a[(n-1)/2];
        for(int i=0; i<n; i++){
            if(a[i]==x){
                total++;
            }
        }
        if(total%2){
            printf("%d",x);
        }else printf("-1");
    }
    else{
        int total=0;
        if(a[n/2]!=a[(n/2)-1]){
            printf("-1");
            return 0;
        }
        else{
            x=a[n/2];
            for(int i=0; i<n; i++){
                if(a[i]==x){
                    total++;
                }
            }
            if(total%2==0){
                printf("%d",x);
            }else printf("-1");         
        }
    }
return 0;
}