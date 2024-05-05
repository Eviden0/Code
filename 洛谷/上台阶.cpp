// #include<bits/stdc++.h>
// using namespace std;
// int sum[20];
// int main(){
//     int n;cin>>n;
// sum[1]=1,sum[2]=2;


// for(int i=3;i<=n;i++){
//     sum[i]=sum[i-1]+sum[i-2];
// }
// cout<<sum[n];
// }
//记忆化搜索

// #include<bits/stdc++.h>
// // #define int long long ;
// int mem[100];
// int dfs(int x){
//     if(mem[x])return mem[x];
//     int sum=0;
//     if(x==1)sum=1;
//     else if(x==2)sum=2;
//     else sum=dfs(x-1)+dfs(x-2);
//     mem[x]=sum;
//     return sum;
// }
// using namespace std;
// signed main(){
// int n;cin>>n;
// int res = dfs(n);
// cout<<res;
// return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int mem[100];
void dfs1(int x){
    //纯暴力搜
    if(x>n)return ;
    if(x==n)cnt++;
    dfs1(x+1);
    dfs1(x+2);
}
//最少(n-1)/2+1次
//最多n次
int dfs2(int x){
    if(x==1||x==2)return x;
    
    return dfs2(x-1)+dfs2(x-2);
}
int main(){
    cin>>n;
    dfs1(0);
    cout<<cnt;
    cout<<endl<<dfs2(n);
}