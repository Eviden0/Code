#include<iostream>
using namespace std;
int n;
int m;
int res;
bool check(int *a,int *b,long long x){
    long long sum=0;
    for(int i=0;i<n;i++){
        // 知道做 5 个药
        sum+=((a[i]*x+b[i]-1)/b[i]);
    }
    if(sum<=m)return true;
    else return false;
}
int main(){

    int t;
    // cin>>t;
    scanf("%d",&t);
    while(t--){
        int need[1005]={0},cous[1005];
        // cin>>n>>m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",&need[i]);
        for(int i=0;i<n;i++)scanf("%d",&cous[i]);
        long long l=0,r=100000000;
        long long mid;

        while(l<=r){    
            mid=(r+l)/2;
            if(check(need,cous,mid)){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
            // cout<<l<<' '<<r<<endl;
        }
        //找sum小于等于 m的x最大值
        printf("%d\n",res);
    }
}