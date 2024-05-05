#include<bits/stdc++.h>
using namespace std;
int a[200010];
int dp[200010];
int main(){
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dp[1]=a[1];int maxx=a[1];
    for(int i=2;i<=n;i++){
        if(dp[i-1]>0)dp[i]=dp[i-1]+a[i];
        else dp[i]=a[i];
        maxx=max(maxx,dp[i]);
    }
    cout<<maxx;
}