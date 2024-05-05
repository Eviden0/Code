#include <bits/stdc++.h>
using namespace std;

int fn(int n){
    int s=0;
    while(n){
   
    int tm=n%10;
    if(tm==8)s+=2;
    else if(tm==9||tm==0||tm==6)s+=1;
   n/=10;
  }
  return s;
}
int dic[100010];
int main()
{   
    memset(dic,0x3c,100010);
  int a,b,maxs=0;
  cin>>a>>b;
  int j=0;
  for(int i=a;i<=b;i++){
    // 保存最大值的序号,并按序输出
    //保存i
    int res=fn(i);
    if(dic[res]<0x3c)continue;
    if(res>maxs){
        maxs=res;
        dic[maxs]=i;
    }
  }
  cout<<dic[maxs];
  // 请在此输入您的代码
  return 0;
}