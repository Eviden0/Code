#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
bool vis[100001];
queue<PII> q;
int bfs(int start,int tar){
    if(start==tar)return 0;
    q.push({start,0});
    while(!q.empty()){
        int num=q.front().first;
        int steps=q.front().second;
        // cout<<num<<' '<<steps<<endl;
        q.pop();
        if(num==tar){return steps;}
        int n1=num*2,n2=num/2,n3=num+1,n4=num-1;
        if(n1<100000&&!vis[n1]){
            q.push({n1,steps+1});
            vis[n1]=1;
        }
        if(!vis[n2]){
            q.push({n2,steps+1});
            vis[n2]=1;
        }
        if(!vis[n3]){
            q.push({n3,steps+1});
            vis[n3]=1;
        }
        if(n4>1&&!vis[n4]){
            q.push({n4,steps+1});
            vis[n4]=1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        //注意初始化!
        queue<PII> emptyQueue;
        q.swap(emptyQueue);
        memset(vis,0,sizeof(vis));
        int s,t;
        cin>>s>>t;
        cout<<bfs(s,t)<<endl;
    }
}