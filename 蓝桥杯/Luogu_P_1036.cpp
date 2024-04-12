#include<bits/stdc++.h>
using namespace std;
int cnt,num[22],arr[22],n,k;
bool vis[22];
bool isPrime(int n){
    int s=sqrt(double(n));
    for(int i=2;i<=s;i++){
        if(n%i==0)return false;
    }
    return true;
}
//3 7 12 19
void dfs(int x,int sum,int next){
    if(x>k){
        // cout<<sum<<endl;
        if(isPrime(sum)){cnt++;
        // cout<<x<<' '<<sum<<' '<<next<<endl;
        }
        return;
    }
    //不能选重复的数,就是组合数
    for(int i=next;i<=n;i++){
        dfs(x+1,sum+num[i],i+1);
    }
    return;
}
// void dfs(int indexlocation,int next){
//     //indexlocation ->当前枚举数位
//     //next -> 从哪一个数开始枚举起
//     /*
//     比如初始时 dfs(1,1)
//     表示枚举第一个位置,从目标数组里第一个数开始搜
//     因此也表示一个位置可以放任何一个数嘛
//     接着到dfs(2,2)
//     此时在第二个位置开搜,也是目的数组的第二个开始
//     */

// //    if(n-next<k-indexlocation)return ;
//    if(num[next]==num[n])return;
//     if(indexlocation>k){
//         int sum=0;
//         for(int i=1;i<=k;i++)sum+=arr[i];
//         // cout<<endl;
//         if(isPrime(sum))cnt++;
//         return ;
//     }
//     //
//     for(int i=next;i<=n;i++){
//         arr[indexlocation]=num[i];
//         dfs(indexlocation+1,i+1);
//         arr[i]=0;
//     }
// }
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>num[i];
    dfs(1,0,1);
    cout<<cnt;
    // for(int i:num)cout<<i<<' ';
}
