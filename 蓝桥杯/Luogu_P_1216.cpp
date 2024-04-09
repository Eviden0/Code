#include<bits/stdc++.h>
using namespace std;

int n;
int num[1010][1010];
int mem[1010][1010];
bool vis[1010][1010];
int dfs(int x,int y){

    if(x<1||x>n||y<1||y>n||y>x)return -1;
    if(x==n)return num[x][y];
    //这里输出的数组全是0的话有bug;
    //如果是这时候通过判断它是否为0来判断它是否被遍历过的话那么会搜很多无用的
    //其实0那个位置已经被遍历过了,所以呢得加一个其他的特判是否搜过!;
    if(vis[x][y]||mem[x][y])return mem[x][y];
    vis[x][y]=true;
    int sum=0;
    sum=max(dfs(x+1,y),dfs(x+1,y+1))+num[x][y];
    mem[x][y]=sum;
    return sum;
}
int main(){
cin>>n;
for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++)cin>>num[i][j];
}
cout<<dfs(1,1);
}