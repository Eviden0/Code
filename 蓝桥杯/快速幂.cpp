#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

/*
    if(b & 1)
	ans *= base;
    与1 进行与运算,可以判断一个数的二进制最后一位是不是1
    
   int n;
   cin>>n;
   bitset<5>binary(n);//c++自带函数自动转2进制!
   5表示二进制转换之后的数位最大是5位
   cout<<binary;
*/
int m;
int quick_power(int a,int b){
    int ans=1,base=a;
    while (b>0)
    {
        /* code */
        if(b&1){
            ans*=base;
            ans%=m;
        }
        base*=base;
        base%=m;
        b>>=1;
    }
    return ans;
}

int qucik(int a,int b){
    int ans=1,base=a;
    while(b>0){
        if(b&1){
            ans*=base;
            ans%=2;
        }
        base*=base;
        base%=2;
        b>>1;
    }
    return ans;
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int a=2,b=11;
cout<<quick_power(2,11);
}