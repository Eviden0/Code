#include<bits/stdc++.h>
using namespace std;

int n,a,b,cnt=1e8;
int num[210];
int arr[210];
void dfs(int x,int sum){
    if(x>n||x<1) return;
    /*这一布判断此时到达x时的次数是否大于之前走过的,很关键!*/
    if(sum>=arr[x])return;
    if(sum>=cnt)return;
    if(x==b){
        cnt=sum;
        return;
    }
    arr[x]=sum;
    //上
    dfs(x+num[x],sum+1);

    //下
    dfs(x-num[x],sum+1);

}
int main(){
cin>>n>>a>>b;
for(int i=1;i<=n;i++){cin>>num[i];arr[i]=1e8;}
//当前是在a,要上到b,输出最短方案次数,没有则输出-1
dfs(a,0);
if(cnt!=1e8)
cout<<cnt;
//注意搜不到答案的情况!!!
else cout<<-1;
}

typedef long long ll;
int n,a,b;
int num[210],dis[210];
//参数只是影响dfs(边界的)条件才加!
void dfs2(int x,int cnt){

    dis[x]=cnt;
    int v=x-num[x];//能下多少层

}
int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)cin>>num[i];
    dfslast(a,0);
}