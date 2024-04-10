/*
输入一个数组,coins 表示不同面额的硬币,以及一个整数amount表示总金额
计算并返回可以凑成的总金额所需的最小硬币个数,没有一种方案则返回-1
*/
//完全背包问题
#include<bits/stdc++.h>
using namespace std;
int amount,n,coins[1010];
int mem[1010];
int dfs(int spa){
    if(spa==0)return 0;
    if(spa<0)return 1e9;
    if(mem[spa])return mem[spa];
    int sum=1e9;
    for(int i=1;i<=n;i++){
        if(coins[i]<=spa)
        // {
            //思考为什么是sum
            //当搜不到答案的时候,返回的就是我们预先设定的1e9+1了这个时候其实应该赋值为1e9的
            sum=min(sum,dfs(spa-coins[i])+1);
            mem[spa]=sum;
        // }
    }
    return sum;
}
int main(){
cin>>n>>amount;
for(int i=1;i<=n;i++)cin>>coins[i];
cout<< dfs(amount);
}