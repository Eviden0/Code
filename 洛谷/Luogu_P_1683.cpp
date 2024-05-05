#include<bits/stdc++.h>
using namespace std;
//h行w列
int sum=0;
int w,h,begin1,begin11;
char way[22][22];
bool vis_way[22][22];
void dfs(int x1,int x2){
    if(x1<1||x1>h||x2<1||x2>w)return;
    if(vis_way[x1][x2])return;
    if(way[x1][x2]=='#')return ;
    if(!vis_way[x1][x2]){sum++;vis_way[x1][x2]=true;}
    dfs(x1,x2-1);
    dfs(x1-1,x2);
    dfs(x1,x2+1);
    dfs(x1+1,x2);
}
int main(){
cin>>w>>h;
for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){cin>>way[i][j];if(way[i][j]=='@'){begin1=i,begin11=j;}}
}
// cout<<begin1<<' '<<begin11;
dfs(begin1,begin11);
cout<<sum;
}




