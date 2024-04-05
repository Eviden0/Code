#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>a;
    for(int i=0;i<4;i++)a.insert(i);
    a.insert(3);
    cout<<a.size();
}