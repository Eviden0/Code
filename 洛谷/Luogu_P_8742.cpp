#include <iostream>
#include <set>
using namespace std;
int n;int a[100];
int main(){
    set<int>group;
    cin>>n;
    //即通过 n个数的加减运算 能运算出多少种结果
    //那就一个一个算呗,用set集合一放,自动去重再统计出结果即可!
    //ok这样分组就写不出了
    //思路应该是动态规划
    for(int i=0;i<n;i++){cin>>a[i];group.insert(a[i]);}
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            group.insert(a[i]+a[j]);
            group.insert(abs(a[i]-a[j]));
        }
        //1 4 6 5 3 7 5 10 2
        //n个数为1组 n从1-3 一组又分为同时在一边和不在一边
    }
    cout<<group.size();
}