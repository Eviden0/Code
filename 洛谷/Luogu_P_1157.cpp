#include<bits/stdc++.h>
using namespace std;
int arr[22];
int n,r;
/*
int x   记录当前枚举到那个位置
int arr[] 记录答案
int start 记录下个位置从几开始枚举
*/
void dfs(int x,int start){
    if(n-start<r-x)return ;
    if(x>r){
        for(int i=1;i<=r;i++){
            printf("%3d",arr[i]);
        }
        cout<<endl;
        return ;
    }
    for(int i=start;i<=n;i++){
        arr[x]=i;
        dfs(x+1,i+1);
        arr[x]=0;
    }
}

// void dfs(int x){
//     //x表示搜到哪个位置
//     if(x>r){
//         for(int i=1;i<=r;i++)
//         printf("%3d",arr[i]);
//         cout<<endl;
//         return ;
//     }
//     // arr[x]=x;
//     for(int i=arr[x-1]+1;i<=n;i++){
//         arr[x]=i;
//         dfs(x+1);
//         // arr[i]=0;
//     }
// }
int arr2[22],vis2[22];
void dfs2(int x,int next){
    if(x>r){
        for(int i=1;i<=r;i++)cout<<setw(3)<<arr2[i];
        cout<<endl;
        return;
    }
    for(int i=next;i<=n;i++){
        arr2[x]=i;
        dfs2(x+1,i+1);
        arr2[x]=0;
    }
}
int main(){
    cin>>n>>r;
    // dfs(1,1);
    dfs2(1,1);
    return 0;
}