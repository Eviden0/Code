#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;//存坐标,二元组
const int N=110;
int n,m;
int g[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int dist[N][N];//存每个点到起点的距离
queue<PII> q;
int bfs(int x1,int y1){
    memset(dist,-1,sizeof dist);
    q.push({x1,y1});
    dist[x1][y1]=0;
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x<1||x>n||y<1||y>m)continue;
            if(g[x][y]!=0)continue;
            if(dist[x][y]>0)continue;
            dist[x][y]=dist[t.first][t.second]+1;
            q.push({x,y});
            // dist[x][y]=dist[t.first][t.second]+1;
            if(x==n&&y==m)return dist[x][y];
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    cout<<bfs(1,1);
}