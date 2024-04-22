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
int main(){
    cout<<read();
    return 0;
}