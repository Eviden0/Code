#include<iostream>

using namespace std;
// int a[100010];
int sum[100010];
int main(){
    int n;
    cin>>n;
    //最小就是单个最大的!
    //前缀和 哟哟哟
    //貌似不需要存原数组???
    //1 2 3 1 2 3
    //1 3 6 7 9 12



    //4 1 3 2 4 1
    //4 5 8 10 14 15
    //5
    int mm=-1;
    int sumx=0,a;

    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        sumx+=a;
        mm=max(a,mm);
        sum[i]=sumx;
        // cout<<sum[i]<<' ';
    }
    // cout<<endl;
    int tm=0;
    // cout<<sumx;
    bool flag=false;
    for(int r=mm;r<=sumx;r++){
        int i=1;
        for(;i<=n;i++){
            if(sum[i]-tm>r)break;
            if(sum[i]-tm==r){
                tm=sum[i];
                flag=true;
            }
        }
        if(i>=n&&flag){
            cout<<r<<endl;
            break;
        }
        tm=0;
    }
    //做法有问题na!
    //等下再好好想想

}