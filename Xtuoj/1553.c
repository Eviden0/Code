#include<stdio.h>
# include<stdlib.h>

int IsHeli(int n){
    int sum=0,tn=n;
    while(tn){
        sum+=tn%10;
        tn/=10;
    }
    if(n%sum==0)return 1;
    else return 0;
}
int main(){
    int T=1000000000;
    // scanf("%d",&T);
    while (T--)
    {
        // //先求数码和
        // char a[10]={0};
        // scanf("%s",a);
        // int sum=0;
        // int num=atoi(a);
        // for(int i=0;a[i]!='\0';i++)sum+=(a[i]-'0');
        // int min=num/sum*sum;
        // // printf("%d-----%d----%d",sum,num,num/sum*sum);
        // // printf("%d\n",num/sum*sum);
        // for(int i=num;i>=num/sum*sum;i--){
        //     if(IsHeli(i)){printf("%d\n",i);break;}
        // }
        int n;scanf("%d",&n);
        for(int i=n;i>=0;i--)if(IsHeli(i)){printf("%d\n",i);break;}
    }

}
