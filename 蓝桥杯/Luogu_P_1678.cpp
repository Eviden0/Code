#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];
int binary_search(int *n,int size,int tar){
    int l=0,r=size-1;
    int m;
    while(l+1<r){
        m=(l+r)/2;
        if(n[m]<tar)l=m;
        else if(n[m]>tar)r=m;
        else if(n[m]==tar){r=m;break;}
    }
    int r1=abs(tar-n[l]),r2=abs(tar-n[r]);
    if(r1>r2)return r2;
    else return r1;
    // return m;
}
int main(){
    int n,m;
    int tm;
    // cin>>n>>m;
    scanf("%d %d",&n,&m);
    int sum=0;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<m;i++){
        scanf("%d",&tm);
        sum+=binary_search(a,n,tm);
    }
    cout<<sum;
}