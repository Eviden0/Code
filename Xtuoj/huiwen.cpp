#include<iostream>
#include<set>
#include<string>
using namespace std;

bool isReverse(string s){
        int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main(){
    int t=1000;
    while (t--)
    {
    string s;
    cin>>s;
    // if(isReverse(s))cout<<"yes\n";
    set<char> dic(s.begin(),s.end());
    // for(auto it = ss.begin();it!=ss.end();it++)
    // { 
    //     // s.insert(1,(*it));//*it是一个解引用字符
    //     // string c(1,*it);
    //     s.insert(s.size(),1,*it);
    // }
    int cnt=0;
    for(int i=0;i<=s.size();i++){
       
    for(auto it=dic.begin();it!=dic.end();++it){
        string ts=s;
        ts.insert(i,1,*it);
        // cout<<ts<<' '<<endl;
         if(isReverse(ts))cnt++;//这是一种并不高效的算法.
         //其实每次插入的地方只能插入那个对称点!因此并不需要set
    }
    cout<<cnt<<endl;
    // cout<<'\n'<<s;
    }
    
    
}