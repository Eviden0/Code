#include<iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        // 1
        // abaacdecdeb
        // 6


        //1
        //ab  |ccbd|  cde
        //4
        int vis[30]={0};
        int bef[1010]={0};
        int k;
        string s;
        //每个字母最多出现k次
        cin>>k>>s;
        for(int i=0;i<s.size();i++){
            vis[s[i]-'a']++;
        }
    }

    
}