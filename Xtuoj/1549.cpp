#include<stdio.h>
#include<cmath>
using namespace std;


int  pow2[31];
bool divideFind(int n[],int leftindex,int size,int tar){
    int left=leftindex,right=size-1;
    while (left<=right)
    {   
        int mid=(left+right)/2;
        if(n[mid]==tar)return true;
        else if(n[mid]>tar) right=mid-1;
        else left = mid +1 ;
    }
    return false;
}
int main() {

for(int i =1;i<31;i++){
    pow2[i]=pow(2,i);
}
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int cnt=0;
        int num[100005]={0};
        for(int i=0;i<n;i++)scanf("%d",&num[i]);
        int maxj=num[n-1]*2;
        // for(int k=1;k<31;k++){
        //     if(pow2[k]>=2*num[n])maxj=k;
        // }
        for(int i=0;i<n-1;i++){
            //num[i]~2j
            //找到最大的j
            for(int j=1;pow2[j]<maxj;j++){
                if(num[i]*2<pow2[j]){
                    // cout<<num[i]<<":"<<pow2[j]<<' ';
                    // cout<<divideFind(num,i+1,n,pow2[j]-num[i])<<" 查找:"<<pow2[j]-num[i]<<' ';
                    if(divideFind(num,i+1,n,pow2[j]-num[i])){cnt++;}
                }
            }
        }
        printf("%d\n",cnt);
    }
    
}


/*

cin 就是这么慢???
*/
// #include<iostream>
// #include<cmath>
// using namespace std;


// int  pow2[31];
// bool divideFind(int n[],int leftindex,int size,int tar){
//     int left=leftindex,right=size-1;
//     while (left<=right)
//     {   
//         int mid=(left+right)/2;
//         if(n[mid]==tar)return true;
//         else if(n[mid]>tar) right=mid-1;
//         else left = mid +1 ;
//     }
//     return false;
// }
// int main() {

// for(int i =1;i<31;i++){
//     pow2[i]=pow(2,i);
// }
//     int T;
//     cin>>T;
//     while (T--)
//     {
//         int n;
//         cin>>n;
//         int cnt=0;
//         int num[100005]={0};
//         for(int i=0;i<n;i++)cin>>num[i];
//         int maxj=num[n-1]*2;
//         // for(int k=1;k<31;k++){
//         //     if(pow2[k]>=2*num[n])maxj=k;
//         // }
//         for(int i=0;i<n-1;i++){
//             //num[i]~2j
//             //找到最大的j
//             for(int j=1;pow2[j]<maxj;j++){
//                 if(num[i]*2<pow2[j]){
//                     // cout<<num[i]<<":"<<pow2[j]<<' ';
//                     // cout<<divideFind(num,i+1,n,pow2[j]-num[i])<<" 查找:"<<pow2[j]-num[i]<<' ';
//                     if(divideFind(num,i+1,n,pow2[j]-num[i])){cnt++;}
//                 }
//             }
//         }
//         cout<<cnt<<endl;
//     }
    
// }


