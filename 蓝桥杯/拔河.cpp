#include<bits/stdc++.h>
using namespace std;
int num[1010],sum[1010],dp[1010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    cin>>num[i];
    sum[i]=sum[i-1]+num[i];
    // cout<<sum[i]<<' ';
    }
    cout<<endl;
    int minn=1e9;
    for(int i=1;i<=n;i++){
        dp[i]=abs(sum[n]-2*sum[i]);
        // cout<<dp[i]<<' ';
        minn=min(dp[i],minn);
    }
    cout<<minn;
}