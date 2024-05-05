#include<bits/stdc++.h>
using namespace std;
int way[17][17];
int n,m,t;//分别表示迷宫的长宽和障碍总数
//n行m列
int sx,sy,fx,fy;//起点终点坐标
int cnt=0;
bool vis[17][17];
void dfs(int x,int y){
    if(vis[x][y])return;
    if(way[x][y]==1)return ;
    if(x<1||x>n||y<1||y>m)return ;
    if(x==fx&&y==fy){cnt++;return ;}
    vis[x][y]=true;
    //4个方向
    dfs(x,y+1);
    dfs(x,y-1);
    dfs(x+1,y);
    dfs(x-1,y);
    vis[x][y]=false;
}
int main(){
cin>>n>>m>>t>>sx>>sy>>fx>>fy;
// cout<<t<<endl;
while (t--)
{
    int x,y;
    cin>>x>>y;
    way[x][y]=1;
}

// for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)cout<<way[i][j];
//         cout<<endl;
//     }
dfs(sx,sy);
cout<<cnt;
}