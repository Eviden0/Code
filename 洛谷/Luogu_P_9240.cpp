#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,maxx=1e9,minx=-1;cin>>n;
    int  a,b;
    //算v,消耗v个普通金属O可以继续冶炼出金属X
    //给出A个金属O,冶炼出B个金属X
    //向上取整+1个
    //向下取整原,得最大
    for(int i=0;i<n;i++){
        cin>>a>>b;
        int t1,t2;
        //向下取整!
        t1=(int)floor(a/b);
        t2=(int)floor(a/(b+1)+1);
        maxx=min(t1,maxx);
        minx=max(t2,minx);
    }
    cout<<minx<<' '<<maxx;
}