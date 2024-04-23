#include<iostream>
using namespace std;
int a[1005],b[1005];
int main(){
    //阶乘的递推 fn = fn-1 * n

    //这里不需要 序号,因此 可以用一维数组简化!
    // int a[52][1000];
    // int b[52][1000];
    // for(int i=3;i<=52;i++){
    //     for(int j=1;i<=100;j++){
    //         a[i][j]*=i;
    //     }

    //     for(int j=1;j<=100;j++){
    //         if(a[i][j]>9){
    //             a[i][j+1]=a[i][j+1]/10;
    //             a[i][j]%=10;
    //         }
    //     }
    int n;
    cin>>n;
    a[0]=b[0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<100;j++)b[j]*=i;
        for(int j=0;j<100;j++){
            if(b[j]>9)b[j+1]+=b[j]/10;
            b[j]%=10;
        }
        //高精度求和
        for(int j=0;j<100;j++){
            a[j]+=b[j];
            if(a[j]>9){
                a[j+1]+=a[j]/10;
                a[j]%=10;
            }
        }

    }
    int i;
    for(i=100;i>=0&&a[i]==0;i--);//去前导0
    for(int j=i;j>=0;j--)cout<<a[j];
}
