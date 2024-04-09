#include<bits/stdc++.h>
using namespace std;
int n;
int m[5050],maxx=-1; 
int main(){
    cin>>n;
    int dp[5050];
    // memset(dp,1,sizeof(dp));
    for(int i=0;i<5050;i++)dp[i]=1;
    // for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
    for(int i=1;i<=n;i++)cin>>m[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(m[i]>m[j])dp[i]=max(dp[j]+1,dp[i]);
        }
        maxx=max(dp[i],maxx);
    }
    cout<<maxx;
}