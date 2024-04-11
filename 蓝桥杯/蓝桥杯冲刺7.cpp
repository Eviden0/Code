#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int mod=998244353;
int arr[1010];
long long cnt=0;
int dp[1010];
void dfs(int x){

    
    if(x>n){
        // for(int i=1;i<=n;i++){
        //     cout<<arr[i]<<' ';
        //     // if(abs(arr[i]-arr[i-1])<k)return;
        // }
        // cout<<endl;
        cnt++;
        cnt%=998244353;
        return;
    }

    for(int i=1;i<=m;i++){
        arr[x]=i;
        if(x>=2)
        if(abs(arr[x]-arr[x-1])<k)continue;
        dfs(x+1);
        arr[x]=0;
    }
}
int main(){
    //选的数量,选数的范围,数的差距
    cin>>n>>m>>k;
    dfs(1);
    // cout<<'\n'<<cnt;
    cout<<cnt;
}