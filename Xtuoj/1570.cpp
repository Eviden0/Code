#include <iostream>
#include <cstring>
using namespace std;
#define Max_rank 3
#define mod 1000000007
struct Matrix {
    long long a[Max_rank][Max_rank];

    Matrix() {
        memset(a, 0, sizeof(a));
    }

    void init(){
        a[1][1] = a[1][2] = a[2][1] = 1;
        a[2][2] = 0;
    }

    Matrix operator*(const Matrix b) {
        Matrix res;
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 2; j++)
                for (int u = 1; u <= 2; u++)
                    res.a[i][j] = (res.a[i][j] + a[i][u]*b.a[u][j])%mod;
        return res;
    }
};

long long q_pow(long long n){
    // if(n==0||n==1)return 1;
    Matrix ans,base;
    ans.init();
    base.init();
    while(n > 0){
        if(n&1) ans =ans *base;
        base = base *base;
        n >>= 1;
    }
    return ans.a[1][1];
}
int main() {
    int t;cin>>t;
    while(t--){
    int a,b;
    cin>>a>>b;
    int ans;
    if(a)cout<<((q_pow(b-1)%mod*q_pow(b)%mod)%mod-(q_pow(a-2)%mod*q_pow(a-1)%mod)+mod)%mod<<endl;
    else cout<<((q_pow(b-1)%mod*q_pow(b)%mod)+mod)%mod<<endl;
    //fib[n]->q_pow(n+1)
    // cout<<q_pow(n-1);

}
    // cout<<q_pow(3-1);
    return 0;
}
//From https://www.cnblogs.com/MMMMMMMW/p/12300262.html