// https://leetcode.cn/problems/integer-break/description/
/*
从1 - n-1个数中选取任意多的数,使其总和为n
要求返回的积最大
*/
#include<bits/stdc++.h>
using namespace std;
int n,tar;
int dp[60];
int sum=0;
int dfs(int x){
    if(x<=1)return 1;
    int sum=-1;
    for(int i=1;i<=x;i++){
        //漏掉了  (x-i)*i???
        //画图其实应该可以看到的
        //第一种:将i 拆分成 j 和 i-j 且i-j不再拆分
        //第二种:拆分成i-j后 i-j可以继续拆分
        sum=max(sum,max(dfs(x-i)*i,(x-i)*i));
    }
    return sum;
    
}
int main(){
cin>>n;
cout<<dfs(n);
}