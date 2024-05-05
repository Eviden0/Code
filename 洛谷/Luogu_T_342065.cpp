#include<bits/stdc++.h>
using namespace std;
//dfs 搜全排列 1-n的全排列
int n,k;
int arr[10010];
bool vis[10010];
void dfs(int x){
    //考虑如何剪枝?

    if(x>n){
        for(int i=1;i<=n;i++)cout<<arr[i]<<' ';
        cout<<endl;
        return;
    }

    for(int i=1;i<=n;i++){
        //没有重复,要记录标记!
        //不然每次都是从1开始搜起,就是错的!
        if(!vis[i]){
        vis[i]=true;
        arr[x]=i;
        dfs(x+1);
        vis[i]=false;
        arr[x]=0;
        }
        
    }
}
int main(){

cin>>n;
dfs(1);
}