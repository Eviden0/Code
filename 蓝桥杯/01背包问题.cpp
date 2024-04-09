#include<bits/stdc++.h>
using namespace std;
int n,tarv;
int res;
int v[1010],w[1010];
int sumW=0;
int mem[1010][1010];
//传参过多,无法剪枝
//超时做法!
void dfs1(int x,int nowV,int sum){
    // if(sum+w[x]<sumW)return;
    if(x>n){
     if(nowV<=tarv&&sum>=sumW)   
        sumW=sum;
        return ;
    }
    dfs1(x+1,nowV,sum);
    if(nowV+v[x]<=tarv)dfs1(x+1,nowV+v[x],sum+w[x]);

}
//mem数组表示搜到每个背包最大价值
//影响搜索边界量是几个,数组就是几维
int dfs(int x,int spV){
    //spV表示剩余体积!
    if(mem[x][spV])return mem[x][spV];
    if(x>n)sumW= 0;
    //不选此项
    else if(v[x]>spV){sumW=dfs(x+1,spV);}
    else if(v[x]<=spV)sumW= max(dfs(x+1,spV),dfs(x+1,spV-v[x])+w[x]);
    mem[x][spV]=sumW;;
    return sumW;
}
int main(){
cin>>n>>tarv;
for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
cout<<dfs(1,tarv);
// cout<<sumW;
}