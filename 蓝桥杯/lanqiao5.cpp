#include<bits/stdc++.h>
using namespace std;
int n;
int a[1010],dp[1010];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];dp[i]=a[i];}
    //dp[i]表示以a[i]开头的递增子序列的最大子序列和!
    // dp[n]=a[n];
    int res=dp[n];
    for(int j=n-1;j>=1;j--){
        int maxx=-1;
        for(int i=n;i>j;i--){
            if(a[i]>a[j]){
                maxx=max(dp[i]+a[j],maxx);
            }
        }
        dp[j]=max(maxx,dp[j]);
        res=max(res,dp[j]);
    }
    cout<<res;
}