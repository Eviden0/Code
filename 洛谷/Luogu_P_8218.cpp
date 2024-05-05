#include<bits/stdc++.h>
using namespace std;
int a[100010],sum[100010];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];
    sum[i]=sum[i-1]+a[i];
    }
    int q;cin>>q;
    while (q--)
    {
        int l,r;cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    

}