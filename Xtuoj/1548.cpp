#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
string s;
bool isReverse(string s){
for(int i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-i-1])return false;
return true;
}
int main(){
    // int n=1001;
    while(cin>>s){//没有输入数量的时候记得把那个输入直接到while里面
    // scanf("%s",s);
    
    int cnt=0;
    for(int i=0;i<=s.size();i++){
        string ts=s;
        if(i<=s.size()/2){
            ts.insert(i,1,s[s.size()-1-i]);
        }
        else{
            ts.insert(i,1,s[s.size()-i]);
        }
        // cout<<ts<<' ';
        if(isReverse(ts))cnt++;
    }
    cout<<cnt<<endl;
    }
}