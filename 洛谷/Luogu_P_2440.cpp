#include<bits/stdc++.h>
using namespace std;
int mood[100010];
typedef long long ll;
int main(){
    int n,k;cin>>n>>k;
    ll sum=0;
    for(int i=0;i<n;i++){cin>>mood[i];}
    //232 124 456  812
    //2 1 4
    //116 
    //灵活运用二分思维,不一定是a[r]<a[mid]这种
    //有些条件可以特判
    int l=0,r=1e8+1,m;
    while(l+1<r){
        m=(l+r)>>1;
        int cnt=0;
        for(int i=0;i<n;i++)cnt+=mood[i]/m;
        if(cnt>=k)l=m;
        else r=m;
    }
    cout<<l<<endl;
    return 0;
}