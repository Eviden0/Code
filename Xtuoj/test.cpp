#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
vector<int> yinzi;
void yinz(int s){
    for(int i=1;i<=sqrt(s);i++){
        if(s%i==0){yinzi.push_back(i);yinzi.push_back(s/i);}
    }
}
int main(){
    int s=100010;
    yinz(s);
    // for(int i=1;i<=10;i++)in.push_back(i);
    for(auto i =yinzi.begin();i!=yinzi.end();i++){
        cout<<*i<<' ';
    }
}