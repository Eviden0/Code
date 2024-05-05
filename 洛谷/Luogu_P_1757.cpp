#include<bits/stdc++.h>
using namespace std;
int maxm,n,m[1004],w[1004],sign[1004];
bool vis[104];
int dp[1004][1004];

int main(){
cin>>maxm>>n;
//01背包
for(int i=1;i<=n;i++){
    int cnt=0;
    //统计组数
    int x;
    cin>>m[i]>>w[i]>>sign[i];//得到组数 
}
for(int i=1;i<=n;i++){
    if(vis[sign[i]])continue;
for(int j=0;j<=maxm;j++){
    int r1=dp[i-1][j],r2=dp[i-1][j-m[i]]+w[i];
    if(m[i]>j) dp[i][j]=r1;
    else {
        if(r2>=r1){
            dp[i][j]=r2;
            //xuan
            vis[sign[i]]=true;
        }
        else dp[i][j]=r1;
    }
}
}
cout<<dp[1][maxm]<<endl;
// int maxre=-1;
// for(int i=1;i<=n;i++){
//     for(int j=1;j<=maxm;j++){
//         // cout<<dp[i][j]<<' ';
//         maxre=max(dp[i][j],maxre);
//     }
// }
// cout<<maxre;
}


/*
本质上动态规划和记忆化搜索是一样的；
都是已知某一个状态的最优状态得出当前状态； 
so即使这题是分组背包，一样可以搜索；
只是多加一个组数的判定 
用了极其朴素的回溯算法的；
见代码吧
代码不长，可以食用 
*/
// #include<bits/stdc++.h>
// using namespace std;
// struct node{
// 	int t;
// 	int v;
// 	int zu;
// }e[1010];//每个物品的花费，收益，组数 
// bool pd[110];//判定组数是否出现 
// int dp[1010];//存结果的 
// int m,n;//如题 
// int dfs(int x)//记忆化搜索 
// {
// 	if(dp[x]>0) return dp[x];// 主体 
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(pd[e[i].zu]) continue;
// 		pd[e[i].zu]=true;
// 		if(x>=e[i].t)
// 		dp[x]=max(dp[x],dfs(x-e[i].t)+e[i].v);
// 		pd[e[i].zu]=false;//回溯 
// 	}
// 	return dp[x];
// }
// int main()
// {
// 	cin>>m>>n;
// 	for(int i=1;i<=n;i++)
// 	cin>>e[i].t>>e[i].v>>e[i].zu;//输入 
// 	for(int i=m;i>=1;i--)
// 	dp[i]=dfs(i);//01背包的板子 
// 	cout<<dp[m]<<endl;
// 	return 0;//结束 
// }
