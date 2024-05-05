#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string s;
  cin>>s;
  int cnt=0;
  for(int i=0;i<s.size();i++){

      if(s[i]=='Q'){cout<<"Q";cnt=0;}
      else
      {
        cnt++;
       if(cnt<2){
       cout<<'L';
    }
      }

  }
  return 0;
}