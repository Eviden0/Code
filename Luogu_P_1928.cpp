#include<bits/stdc++.h>

using namespace std;
string read(){
    int n;
    string s="",s1="";
    char c;
    while (cin>>c)
    {
        /* code */
        if(c=='['){
            cin>>n;
            s1=read();
            while(n--)s+=s1;
        }
        else {
            if(c==']')return s;
            else s+=c;
        }
    }
    return s;
}
string digui(){
    string r="",tr="";
    int n;
    char c;
    while (cin>>c)
    {
        /* code */
        if(c=='['){
            cin>>n;
            tr=digui();//递归搜索应该扩展的字符串
            while(n--)r+=tr;//将递归搜索的结果保存结果字符串,有几个n就保存几次
        }
        else {
            if(c==']')return r;
            else r+=c;
        }

    }
    cout<<r;
    return r;
}
int main(){
    // cout<<read();
    digui();
    return 0;
}