#include<bits/stdc++.h>
using namespace std;
int a,b,p;
int quick_power(int a,int b,int m){
    int ans=1,base=b;
    while(b>0){
        if(b&1){
            ans *= base;
            ans %= m;
        }
        base=(base%modp)*(base%modp)%modp;
        b>>=1;
    }
    return ans%m;
}
int main(){
cin>>a>>b>>p;
cout<<quick_power(a,b,p);
}