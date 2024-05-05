#include<iostream>
#include<set>
using namespace std;
// int a[100005];

int main(){
int n,k;cin>>n>>k;
set<int> a;
for(int i=0;i<n;i++){
    int x;scanf("%d",&x);
    a.insert(x);
}
for(int i:a)cout<<i<<' ';
bool flag=true;
while(1){
    if(a.size()==1){break;}
    int x1=*a.begin();
    a.erase(x1);
    int x2=*a.begin();
    
    if(x2-x1>k){
        flag=false;
        break;
    }
    a.erase(x2);
    a.insert((x1+x2)/2);
}
if(flag)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
// for(int i:a)cout<<i<<' ';
//出现相邻两个数超过距离k直接pass
//1 3 4 6
//1 5 7 k=2
}