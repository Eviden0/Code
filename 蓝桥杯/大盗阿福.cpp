#include<bits/stdc++.h>
using namespace std;
int a[100],num[100];
int mem[100];
int n;
//记忆化搜索
int dfs(int x){
    if(mem[x]) return mem[x];
    
    int sum=0;
    if(x>n) return 0;
    else sum=max(dfs(x+1),dfs(x+2)+a[x]);
    mem[x]=sum;
    // cout<<sum<<' ';
    return sum;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    // sum[i]=sum[i-2]+a[i]
    //上面是错误的递推!
    //正确的应该是:
    //sum[i]=max(sum[i-1],sum[i-2]+a[i]);
    num[1]=a[1];num[2]=max(a[2],a[1]);
    int maxx=max(num[1],num[2]);
    for(int i=3;i<=n;i++){
        num[i]=max(num[i-2]+a[i],num[i-1]);
        if(num[i]>maxx)maxx=num[i];
    }
    cout<<maxx;
    // cout<<dfs(1);
}

