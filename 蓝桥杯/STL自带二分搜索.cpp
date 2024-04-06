#include<iostream>
#include<algorithm>

using namespace std;
int num[10000010],tar[100010];
int main(){
    // int a[]={1 ,3, 3, 3, 5, 7, 9, 11, 13, 15, 15};
    int n,m;cin>>n>>m; 
    for(int i=1;i<=n;i++)scanf("%d",&num[i]);
    for(int i=1;i<=m;i++)scanf("%d",&tar[i]);
    //find 1 3 6
    for(int i=1;i<=m;i++)
  {  
    // int find;cin>>find;
    int result=lower_bound(num+1,num+1+n,tar[i])-num;
    if(num[result]==tar[i])cout<<result<<' ';
    else cout<<-1<<' ';
    }
    //返回大于等于 查找的最小位置
}