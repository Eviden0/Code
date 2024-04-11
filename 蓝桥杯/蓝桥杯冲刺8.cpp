#include<bits/stdc++.h>

using namespace std;
long long n,k; 
long long num[100010];
long long cnt=0;
long long m=1e9+7;
long long quick_power(long long a,long long b){
    long long ans=1,base=a;
    while (b>0)
    {
        /* code */
        if(b&1){
            ans*=base;
            ans%=m;
        }
        base*=base;
        base%=m;
        b>>=1;
    }
    ans%=m;
    return ans;
}
int main(){
    //数组最小的加上最大的<=k
   cin>>n>>k;
   for(int i=1;i<=n;i++){
    cin>>num[i];
//    if(2*num[i]<=k)cnt++;
   }
   sort(num+1,num+1+n);
   int l=1,r=n;
    while(l<=r){
        // 取模运算一定记得多次取模啊!
        if(num[l]+num[r]<=k){cnt+=quick_power(2,r-l)%m;l++;}
        else r--;
    }
   cout<<cnt%m;
}
