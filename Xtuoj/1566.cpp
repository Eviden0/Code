#include<iostream>
#include<algorithm>
using namespace std;
long long n,k;
bool flag;
long long a[100005],from_min[100005],from_max[100005];
void init(){
    for(int i=0;i<n;i++){
        from_min[i]=1e9;
        from_max[i]=-1e9;
    }
}
int main(){
cin>>n>>k;
//关键在于对不用合并的点位的处理!
init();
for(int i=0;i<n;i++)scanf("%d",&a[i]);
sort(a,a+n);
from_max[0]=a[0];
//从小到大
for(int i=1;i<n;i++){
    if(abs(a[i]-from_max[i-1])<=k)from_max[i]=(a[i]+from_max[i-1])>>1;
}
from_min[n-1]=a[n-1];
//从大到小
for(int i=n-2;i>=1;i--)if(abs(a[i]-from_min[i+1])<=k)from_min[i]=(a[i]+from_min[i+1])>>1;
for(int i=0;i<n-1;i++){
    if(abs(from_max[i]-from_min[i+1])<=k){flag=true;break;}
}
if(flag)printf("Yes\n");
else printf("No\n");
}