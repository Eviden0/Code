// 它们各自的酸度 s 和苦度 b。
// 当我们添加配料时，总的酸度为每一种配料的酸度总乘积；
// 总的苦度为每一种配料的苦度的总和。
// 众所周知，美食应该做到口感适中，所以我们希望选取配料，
// 以使得酸度和苦度的绝对差最小。

// 另外，我们必须添加至少一种配料，因为没有任何食物以水为配料的。
#include<bits/stdc++.h>
using namespace std;
int n;
int minn=INT32_MAX;

int vis[12];
int s[12],b[12];
void dfs(int x){
    if(x>n){
        bool not_null=false;
        int sji=1,bhe=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                not_null=true;
                sji*=s[i],bhe+=b[i];
            }
        }
        if(not_null)
        minn=min(minn,abs(sji-bhe));
        return ;
    }

    //选 1
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
    //不选 2
    vis[x]=2;
    dfs(x+1);
    vis[x]=0;
    //没考虑 0
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i]>>b[i];
    dfs(1);
    cout<<minn;
}