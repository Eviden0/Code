#include<iostream>
#include<algorithm>
#include <string.h>
using namespace std;
// int num[100010];
//sn=(a⋅sn−1+b)mod m
int main(){
int T,a,b,m;
cin>>T;
while (T--)
{
    cin>>a>>b>>m;
    if(m==1){
        cout<<1<<endl;
        continue;
    }
    long long now=0;//不开longlong见祖宗
    // memset(num,0,100000);
    int num[100010]={0};
    num[0]=1;
    for(int i=0;i<m+1;i++){
        now=(now*a+b)%m;
        if(!num[now])num[now]++;
        else break;
    }


    for(int i=0;i<=m;i++){
        if(num[i]==0){cout<<i<<endl;break;}
    }
}
}



