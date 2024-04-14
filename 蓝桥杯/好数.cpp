#include<bits/stdc++.h>
using namespace std;

bool is_right(int n){
    string s=to_string(n);
    int len=s.size();

    //121
    for(int i=len-1;i>=0;i--){
        if((len-i)%2!=0){if((s[i]-'0')%2==0)return false;}
        else if((s[i]-'0')%2!=0)return false;
    }
    // cout<<setw(3)<<s;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long cnt=0;
        int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(is_right(i))cnt++;
    }
    cout<<cnt;
}