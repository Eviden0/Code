#include<iostream>
using namespace std;
//暴力枚举必将超时
//本题采用二分法枚举

int N,K,h[100002],w[100002];
bool check(int x){
    int s=0;
    for(int i=1;i<=N;i++)s+=(h[i]/x)*(w[i]/x);
    if(s>=K)return true;
    return false;
}
int main(){

    cin>>N>>K;
    for(int i=1; i<=N; i++) cin>>h[i]>>w[i];
    int l=1,r=100002;
    while (l<r)
    {
        /* code */
        int mid = (l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;

    
}