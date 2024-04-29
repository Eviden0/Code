#include<iostream>
using namespace std;
typedef long long ll ;
int a[100005];
int main(){
    int w,n,d;
    cin>>w>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    a[0]=1,a[n+1]=w;
    if(1+d>=w)cout<<-1;
    else
    {
        int ans=n;
        int l=0,r=0;
        // for(int i=0;i<=n+1;i++)cout<<a[i]<<' ';
        while(r<=n+1&&ans>=0){
            if(a[r]-a[l]>d){ans--;l++;}
            r++;
        }
        cout<<ans;
    }
}