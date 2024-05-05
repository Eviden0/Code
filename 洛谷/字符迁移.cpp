#include<iostream>
using namespace std;
long long a[30];
string zom="abcdefghijklmnopqrstuvwxyz";
#define int long long
// char s[30];
signed main(){
    int n,q;cin>>n>>q;
    // for(int i=1;i<=n;i++)scanf("%c",&s[i]);
    string s;cin>>s;
    int  l,r,k;
    //把所有的移动次数先读完再加对应的偏移量
    for(int i=0;i<q;i++){
        cin>>l>>r>>k;
        for(int j=l;j<=r;j++)a[j]+=k;
    }
    // for(int i=1;i<=n;i++)printf("%c",(s[i]));
    for(int i=0;i<n;i++)
    // printf("%c",(zom[s[i]-'a'+a[i+1]%26]));
    // printf("%d ",s[i]-'a'+a[i+1]%26);
    {   
        cout<<zom[(s[i]-'a'+(a[i+1]%26))%26];}
    // cout<<endl;
    // for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    
}