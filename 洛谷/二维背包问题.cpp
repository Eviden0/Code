#include<bits/stdc++.h>
using namespace std;
int n,maxv,maxm,v[1010],m[1010],w[1010];
int res;
//此处数组不能开这么大!
//会爆空间
//应考虑降维数组
// int mem[1001][1001][1001];
int mem[1][1][1];
int f[101][101];
int dfs(int x,int spv,int spm){
    int sum;
    if(mem[x][spv][spm])return mem[x][spv][spm];
    if(x>n)return 0;
    else 
    {
    if(spv<v[x]||spm<m[x]) sum= dfs(x+1,spv,spm);
    
    //xuan
    else return max(dfs(x+1,spv,spm),dfs(x+1,spv-v[x],spm-m[x])+w[x]);
    }
    mem[x][spv][spm]=sum;
    return sum;

}
int main(){
cin>>n>>maxv>>maxm;
for(int i=1;i<=n;i++)cin>>v[i]>>m[i]>>w[i];
for(int i=1;i<=n;i++){
    for(int j=maxv;j>=v[i];j--){
        for(int k=maxm;k>=m[i];k--){
            //只跟剩余重量体积有关系
            f[j][k]=max(f[j][k],f[j-v[i]][k-m[i]]+w[i]);
        }
    }
}
cout<<f[maxv][maxm];
}