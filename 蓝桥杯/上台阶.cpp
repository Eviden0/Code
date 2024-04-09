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

#include<bits/stdc++.h>
// #define int long long ;
int mem[100];
int dfs(int x){
    if(mem[x])return mem[x];
    int sum=0;
    if(x==1)sum=1;
    else if(x==2)sum=2;
    else sum=dfs(x-1)+dfs(x-2);
    mem[x]=sum;
    return sum;
}
using namespace std;
signed main(){
int n;cin>>n;
int res = dfs(n);
cout<<res;
return 0;
}