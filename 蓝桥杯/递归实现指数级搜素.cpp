#include<iostream>

using namespace std;
int n;int st[20];
void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            if(st[i]==1){
                printf("%d ",i);
            }
        }
        cout<<endl;
        return ;
    }
    //不选
    st[x]=2;
    dfs(x+1);
    st[x]=0;

    //选
    st[x]=1;
    dfs(x+1);
    st[x]=0;
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}