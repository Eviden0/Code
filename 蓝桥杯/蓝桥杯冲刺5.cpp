#include<bits/stdc++.h>
using namespace std;
int n;
int a[1010],dp[1010];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=a[i];
    }
    //dp[i]表示以a[i]结尾的递增子序列的最大子序列和!
    int maxx=-1;
    for(int i=1;i<=n;i++){
        // cout<<dp[i]<<' ';
        for(int j=1;j<=i;j++){
            if(a[i]>a[j])dp[i]=max(dp[i],dp[j]+a[i]);
        }
    }
    int res=*max_element(dp+1,dp+1+n);
    cout<<res;
}

//深搜解法!
// #include<iostream>
// #include<algorithm>
// #include<cstring>
// using namespace std;
// int n;
// int a[1010];
// int arr[1010];
// int maxi=0;
// int dfs(int x){
//     if(arr[x])return arr[x];
//     int ans=0; 
//     for(int i=1;i<x;i++){
//         if(a[i]<a[x]){
//             ans=max(ans,dfs(i)+a[i]);
//         }
//     }
//     arr[x]=ans;
//     return arr[x];
// }
// int main(){
//     memset(arr,0,sizeof(arr));
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++){
//         scanf("%d",&a[i]);
    
//     }
//     for(int i=1;i<=n;i++){
//         maxi=max(dfs(i)+a[i],maxi);
//     }
//     printf("%d",maxi);
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int a[1010],dp[1010];

// int main(){
//     cin>>n;
//     for(int i=1;i<=n;i++){cin>>a[i];dp[i]=a[i];}
//     //dp[i]表示以a[i]开头的递增子序列的最大子序列和!
//     // dp[n]=a[n];
//     int res=dp[n];
//     for(int j=n-1;j>=1;j--){
//         int maxx=-1;
//         for(int i=n;i>j;i--){
//             if(a[i]>a[j]){
//                 maxx=max(dp[i]+a[j],maxx);
//             }
//         }
//         dp[j]=max(maxx,dp[j]);
//         res=max(res,dp[j]);
//     }
//     // for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
//     cout<<res;
// }