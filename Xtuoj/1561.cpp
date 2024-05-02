#include<iostream>
using namespace std;
int n;
int m;
bool check(int *a,int *b,int x){
    int sum=0;
    for(int i=0;i<n;i++){
        // 知道做 5 个药
        sum+=((a[i]*x+b[i]-1)/b[i]);
    }
    if(sum<=x)
    return true;
    else return false;
}
int main(){

    int t;
    while(t--){
        int need[1005]={0},cous[1005];
        cin>>n>>m;
        for(int i=0;i<n;i++)scanf("%d",&need[i]);
        // a1 a2 a3 =1:1:1
        // r*m1+s*m2+t*m3 =10;
        long long l=1,r=10000000000;
        long long mid=(r+l)/2;
        while(l+1<r){
            if(check(need,cous,mid)){
                
            }
        }
    }



}