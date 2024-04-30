#include<iostream>
using namespace std;
typedef long long ll ;
int a[100005];
int main(){
    int w,n,d;
    cin>>w>>n>>d;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=1,a[n+1]=w;
    int ans=1e9,cnt=0;
    int l,r;
    if(1+d>=w)cout<<-1<<endl;
    else
    {   
        l=0,r=0;
        while(r<=n+1){
            // cnt=n;
            while(a[r]-a[l]>d){
                l++;
                // if(r==l)break;
                ans=min(ans,r-l);
            }
            r++;
        }
        cout<<ans<<endl;
    }
}

