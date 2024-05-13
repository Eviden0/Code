#include<iostream>

using namespace std;
int a[100005];
int main(){
    int t;cin>>t;
    while(t--){
        int n,m,l,r;
        cin>>n>>m>>a[0]>>a[1]>>l>>r;
        for(int i=2;i<n;i++)a[i]=(a[i-1]%m)+(a[i-2]%m);
    }
}