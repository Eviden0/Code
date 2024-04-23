#include <iostream>


//其实本题就是一个fib数列问题呗
//只不过数据量大点,ok那我们手动实现一下求fib 第 100 项
//递推关系      fn=fn-1+fn-2
using namespace std;
int a[1002][610];
bool pd=0;
int main(){
    a[0][1]=0;
    a[1][1]=1;
    a[2][1]=2;
    int m,n;
    cin>>m>>n;
    int t=n-m;
    for(int i=3;i<=t;i++){
        for(int j=1;j<600;j++){
            // if(!a[i-1][j]&&!a[i-2][j])continue;
            a[i][j]=a[i-1][j]+a[i-2][j];
        }

        for(int j=1;j<600;j++){
            while (a[i][j]>9)
            {
                a[i][j+1]++;
                a[i][j]-=10;
            }
            
        }
    }
    for(int i=600;i>=1;i--){
        if(!pd&&a[t][i]==0)continue;
        pd=1;//不输出前导0
        cout<<a[t][i];
    }
    // cout<<a[t][1];
}
