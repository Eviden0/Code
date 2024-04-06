#include <iostream>
#include<algorithm>
using namespace std;
int num[200010];

bool check1(int index,int tar){
    if(index < tar)return true;
    return false;
}

bool check2(int index,int tar){
    if(index > tar)return true;
    return false;
}

int binasearch_lower(int n[],int size,int tar){
    //0 1 | 3, 3, 3, 5, 7
    //看这个分界线
    int left=0,right=size;
    while (left+1<right)
    {
        /* code */
        int mid = (left+right)/2;
        if(check1(n[mid],tar)){
            left=mid;
        }else right=mid;
    }
    if(n[right]==tar)return right;
    else return -1; 
}

int binasearch_upper(int n[],int size,int tar){
    //1 , 3, 3, 3,| 5, 7
    //看这个分界线
    int left=0,right=size;
    while (left+1<right)
    {
        /* code */
        int mid = (left+right)/2;
        if(check2(n[mid],tar)){
            right=mid;
        }else left=mid;
    }
    if(n[left]==tar)return left;
    else return -1;
    // return 0;
}
int main(){
    //find cnt A-B=C  =>find A=B+C 
    long N,C,cnt=0;cin>>N>>C;
    // num[0]=0;
    for(int i=1;i<=N;i++)cin>>num[i];
    sort(num+1,num+N+1);
    for(int i=1;i<=N;i++){
        //1 1 2 3
        //枚举B 搜A
        cout<<(binasearch_upper(num,N+1,num[i]+C))<<' '<<(binasearch_lower(num,N+1,num[i]+C))<<endl;
        int r1=binasearch_lower(num,N+1,num[i]+C);
        if(r1!=-1)
        cnt+=(binasearch_upper(num,N+1,num[i]+C)-r1+1);
    }
    // for(int i=1;i<=N;i++){
    //     cnt+=((upper_bound(num+1,num+N+1,num[i]+C)-num)-(lower_bound(num+1,num+N+1,num[i]+C)-num));
    // }
    cout<<cnt;
}