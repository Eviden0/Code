#include<bits/stdc++.h>
using namespace std;
int a[1010];
int dp[1010];
int main(){
    int n;cin>>n;
    //top is n
    for(int i=0;i<=n;i++)cin>>a[i];
    dp[0]=0,dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+a[i-1],dp[i-2]+a[i-2]);
    }
    cout<<dp[n];
}