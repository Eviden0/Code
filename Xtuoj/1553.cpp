// #include<stdio.h>
// # include<stdlib.h>

// int IsHeli(int n){
//     int sum=0,tn=n;
//     while(tn){
//         sum+=tn%10;
//         tn/=10;
//     }
//     if(n%sum==0)return 1;
//     else return 0;
// }
// int main(){
//     int T=1000000000;
//     // scanf("%d",&T);
//     while (T--)
//     {
//         // //先求数码和
//         // char a[10]={0};
//         // scanf("%s",a);
//         // int sum=0;
//         // int num=atoi(a);
//         // for(int i=0;a[i]!='\0';i++)sum+=(a[i]-'0');
//         // int min=num/sum*sum;
//         // // printf("%d-----%d----%d",sum,num,num/sum*sum);
//         // // printf("%d\n",num/sum*sum);
//         // for(int i=num;i>=num/sum*sum;i--){
//         //     if(IsHeli(i)){printf("%d\n",i);break;}
//         // }
//         int n;scanf("%d",&n);
//         for(int i=n;i>=0;i--)if(IsHeli(i)){printf("%d\n",i);break;}
//     }

// }


#include<iostream>
#include<string>
#include<cmath>

//请求不大于n的   最大的“合理”数
using namespace std;
int t;
int sum_num(int n){
    int sum=0;
    while (n!=0)
    {
        /* code */
        sum+=n%10;
        n/=10;
    }
    
    return sum;
}

bool is_heli(int n,int tar){
    if(n%tar==0)return true;
    return false;
}
int main(){
    // cin>>t;
    scanf("%d",&t);
    int n;
    while (t--)
    {
        cin>>n;
        for(int i=n;i>=0;i--){
            int numsum=sum_num(i);
            if(is_heli(i,numsum)){
                cout<<i<<endl;
                break;
            }
        }
        // bool flag=0;
        // //numsum要变的其实
        // for(int i=n1;i>=sqrt(n1);i--){
        //     if(i%numsum==0){printf("%d\n",i);flag=1;break;}
        // }
        // if(!flag)
        // printf("1\n");
    }

}