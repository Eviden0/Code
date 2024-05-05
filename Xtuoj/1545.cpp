#include<iostream>
using namespace std;
string st;

long long dfs(int s,int e){
    long long ans=0;
    //解析s到e之间的表达式
    int cnt=0,p;
    if(st[s]=='('){
        cnt++;
        for(int i=s+1;i<=e;i++){
            //迫切匹配!
            if(st[i]=='(')cnt++;
            if(st[i]==')')cnt--;
            if(!cnt){
                p=i+1;break;
            }
        }
    }
        if(p<e)ans=dfs(p,e);
        if(p-1-s==2)ans+=st[s+1]-'0';
        else {
            long long tmre=dfs(s+1,p-1);
            ans+=tmre*tmre;
        }
        // cout<<"左边界: "<< s <<' '<<"右边界: "<<e<<' '<<"本次的答案: "<<ans<<' '<<endl;
    //((1)(2)(3))
    // if(e-s!=st.size())
    return ans;
    // else return ans*ans;
}
int main(){
    while(cin>>st){
        // ans=0;
        long long res=dfs(0,st.size());
        cout<<res*res<<endl;
    }
}