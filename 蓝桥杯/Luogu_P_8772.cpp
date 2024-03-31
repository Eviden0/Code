#include<iostream>
using namespace std;
long long sum[200005];
int input[200005];
/*
a1(a2+a3+...an)
a2(a3+a4+...an)
...
an-1*an
*/
int main(){
    int N;
    cin>>N;

    // long long before=0;
    for(int i=1;i<=N;i++){
    cin>>input[i];
    sum[i]=sum[i-1]+input[i];
    }
    long long  total=0;
    for(int i=1;i<=N-1;i++){
        // for(int j=i+1;j<N;j++){
        //     sum[i]+=input[i]*input[j];
        // }
        //1,3,6,9
        // before-=input[i];
        // sum[i]=before*input[i];
    total+=(input[i]*(sum[N]-sum[i]));
    }
    // for(int i=0;i<N;i++)total+=sum[i];
    cout<<total;
}