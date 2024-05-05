#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;

int arr[9];
// void dfs(int x,int s,int cur){
//     if(cur==k){
//         if(s==n){
//             cnt++;
//         }
//         return;
//     }
//     for(int i=x;s+i*(k-cur)<=n;i++){
//         dfs(i,s+i,cur+1);
//     }
// }

void dfs(int x,int s){
    // if(x==k)cout<<s<<' ';
    if(x>k){
        // cout<<(n-s)/(k-x+2)<<endl;
        if(s!=n)return;
       
        for(int i=1;i<=k;i++){
            cout<<arr[i]<<' ';
        }
        cnt++;
        cout<<endl;
        return;
    }
    for(int i=1;i*(k-x+1)<=(n-s);i++){
        arr[x]=i;
        if(arr[x]>=arr[x-1])dfs(x+1,s+i);
        arr[x]=0;
    }
    return;
}

int main(){
    cin>>n>>k;
    //最大 n-k+1
    dfs(1,0);
    cout<<cnt;
}