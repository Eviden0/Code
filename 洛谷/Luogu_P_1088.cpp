// /*
// 123  1
// 132  2
// 213  3
// 231  4
// 312  5
// 321  6
// 全排列嘛!
// */

// #include<bits/stdc++.h>
// using namespace std;
//  int n,m;
//  bool vis[10010];
// int arr[10010],num[10010],cnt=0;
// bool flag=false;
// void dfs(int index){
// //如果给的就是12345,那就刚好符合是全排列
// //如果给的是全排列中的某一个中间情况
// //那就需要再加上偏移值m个情况后的下一个情况即为答案
// if(flag){return ;}
// if(index>n){
//     cnt++;
//     if(cnt==m+1)
// {    for(int i=1;i<=n;i++)cout<<arr[i]<<' ';
//     cout<<endl; flag=true;}
//     return ;
// }
// for(int i=1;i<=n;i++){
//     if(cnt==0){
//         //第一次开始从火星数那里开始搜!
//         i=num[index];
//     }
//     if(!vis[i]){
//         vis[i]=true;
//         arr[index]=i;
//         dfs(index+1);
//         vis[i]=false;
//         arr[index]=0;
//     }
// }

// }
// int main(){
   
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)scanf("%d",&num[i]);
//     // for(int i=1;i<=n;i++)cout<<num[i]<<' ';
//     dfs(1);
// }
#include<bits/stdc++.h>
using namespace std;
int n,tar,num[10010],arr[10010],vis[10010],cnt=0;
bool  flag=false;
void dfs(int x){
    if(flag)return;
    if(x>n){
        
        if(cnt==tar)
{        for(int i=1;i<=n;i++)cout<<arr[i]<<' ';
        cout<<endl;
        flag=true;}
        cnt++;
        return;
    }

    for(int i=1;i<=n;i++){
        if(cnt==0)i=num[x];
        if(vis[i])continue;
        vis[i]=true;
        arr[x]=i;
        dfs(x+1);
        arr[x]=0;
        vis[i]=false;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>tar;
    for(int i=1;i<=n;i++)cin>>num[i];
    dfs(1);
}