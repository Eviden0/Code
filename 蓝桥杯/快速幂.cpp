#include<bits/stdc++.h>
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
int quick_power(int a,int b){
    int ans=1,base=a;
    while (b>0)
    {
        /* code */
        if(b&1)ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}


int main(){

int a=2,b=11;
cout<<quick_power(2,11);
}