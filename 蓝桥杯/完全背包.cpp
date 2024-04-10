#include<bits/stdc++.h>
using namespace std;
int n,maxv,v[1011],w[1011];
int mm[1011][1011];
int dfs(int x,int spv){
    if(mm[x][spv])return mm[x][spv];
    if(x>n)return 0;
    int sum=0;
    if(spv<v[x])sum=dfs(x+1,spv);
    else sum=max(dfs(x+1,spv),dfs(x,spv-v[x])+w[x]);
    mm[x][spv]=sum;
    return sum;
}

int main(){
    cin>>n>>maxv;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    cout<<dfs(1,maxv);
}