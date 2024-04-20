#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    int n[5]={1,2,3,1,2};
    unordered_map<int,int> mp;
    for(int i=0;i<5;i++)mp[n[i]]++;
    cout<<mp[3]<<endl;
    for(auto i=mp.begin();i!=mp.end();i++)cout<<i->first<<' '<<i->second<<endl;
}