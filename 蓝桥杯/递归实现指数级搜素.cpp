#include<iostream>

using namespace std;
int n;int st[20];
void dfs1(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            if(st[i]==1){
                printf("%d ",i);
            }
        }
        cout<<endl;
        return ;
    }
    //不选
    st[x]=2;
    dfs1(x+1);
    st[x]=0;

    //选
    st[x]=1;
    dfs1(x+1);
    st[x]=0;
}
int vis[20];
void dfs2(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            if(vis[i]==1)cout<<i<<' ';
        }
        cout<<endl;
        return ;
    }

    vis[x]=1;
    dfs2(x+1);
    vis[x]=0;

    //1表示选
    // vis[x]=2;
    dfs2(x+1);
    // vis[x]=0;

    //2 表示不选
   
    //0表示未考虑

}
int main(){
    cin>>n;
    //1-n 任意选取随机多数,每种数只有选或不选的状态
    dfs1(1);
    dfs2(1);
    return 0;
}