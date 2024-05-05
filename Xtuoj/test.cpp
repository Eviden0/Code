#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long fib[50];
long long sum[50];
long long bin_to_dec(vector<int>a){
    long long now=1,sum=0;
    // for(auto i=a.begin();i!=a.end();i++){
    //     // cout<<(*i)<<' ';
    //     sum+=(now*(*i));
    //     now*=2;
    // }
    for(int i:a)sum+=(now*i),now*=2;
    return sum;
}
int main(){

    fib[0]=1;
    sum[0]=1;
    sum[1]=3;
    fib[1]=2;
    // cout<<1<<' '<<2<<' ';
    // int x=1000000000;
    int end=42;
    for(int i=2;i<end;i++){
        fib[i]=fib[i-1]+fib[i-2];
        sum[i]=sum[i-1]+fib[i];
        // cout<<fib[i]<<' ';
    }
    int n;
    cin>>n;
    while(n--){
    int x;
    cin>>x;
    if(x==1){cout<<1<<endl;continue;}
    // long long tar=100;
    int index=upper_bound(sum,(sum+end),x)-sum;
    if(x==sum[index-1]){
            // cout<<"米表"<<index<<' '<<x<<' '<<sum[index-1]<<' '<<fib[index-1]<<endl;
        vector<int> re(index,1);
        cout<<bin_to_dec(re)<<endl;
        continue;
        // for(int i=index-1;i>=0;i--)re[i]=1;
    }
    // cout<<index<<' '<<sum[index]<<' '<<fib[index]<<endl;
    vector<int> re(index+1,0);
    re[index]=1;
    x-=fib[index];
    while(x){
        index=upper_bound(sum,(sum+end),x)-sum;
        // cout<<index<<' '<<x<<' '<<sum[index-1]<<' '<<fib[index-1]<<endl;
        if(x==sum[index-1]){
            // cout<<"米表"<<index<<' '<<x<<' '<<sum[index-1]<<' '<<fib[index-1]<<endl;
            for(int i=index-1;i>=0;i--)re[i]=1;
            break;
        }else {
            re[index]=1;
            x-=fib[index];
        }
    }
    // cout<<endl;
    // for(auto i =re.end()-1;i>=re.begin();i--)cout<<*i;
    cout<<bin_to_dec(re)<<endl;
    // cout<<endl;
    // for(int i=0;i<end;i++)cout<<sum[i]<<' ';
    }
}
//111011011010110111111101011101111101111111