#include<iostream>

#include<string>
using namespace std;
int IsHeli(int n){
    int sum=0,tn=n;
    while(tn){
        sum+=tn%10;
        tn/=10;
    }
    if(n%sum==0)return sum;
    else return 0;
}
int main(){
    for(int n=1000000000;n>=1;n--){
        if(IsHeli(n))cout<<n<<' ';
    }
}