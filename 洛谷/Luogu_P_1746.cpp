#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
int x1,x2,y1,y2;
int n;
char p[1010][1010];
int dis[1010][1010];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<PII> q;
int bfs(int xx,int yy){
    memset(dis,-1,sizeof dis);
    q.push({xx,yy});
    dis[xx][yy]=0;
    while(q.size()){
        auto t=q.front();q.pop();
        for(int i=0;i<4;i++){
            int x=t.first+dx[i];
            int y=t.second+dy[i];
            if(x<1||x>n||y<1||y>n)continue;
            if(p[x][y]!='0')continue;//已经走过的路!pass

            if(dis[x][y]>0)continue;
            dis[x][y]=dis[t.first][t.second]+1;
            q.push({x,y});
            if(x==x2&&y==y2)return dis[x][y];
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>p[i][j];
        }
        // getchar();
    }
    cin>>x1>>y1>>x2>>y2;
    cout<<bfs(x1,y1);
}