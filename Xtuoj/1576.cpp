#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
// int a[100010];
int sum[100010];
vector<int> yinzi;
void yinz(int s){
    for(int i=1;i<=sqrt(s);i++){
        if(s%i==0){yinzi.push_back(i);yinzi.push_back(s/i);}
    }
}
int main(){
    int n;
    cin>>n;
    //最小就是单个最大的!
    //前缀和 哟哟哟
    //貌似不需要存原数组???
    //1 2 3 1 2 3
    //1 3 6 7 9 13

    //4 1 3 2 4 1
    //4 5 8 10 14 15
    //5
    int sumx=0,a;

    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        sumx+=a;
        // mm=max(a,mm);
        sum[i]=sumx;
        // cout<<sum[i]<<' ';
    }
    // cout<<endl;
    int tm=0;
    yinz(sumx);
    // set<int> yinzi1(yinzi.begin(),yinzi.end());
    sort(yinzi.begin(),yinzi.end());
    if(!sumx){cout<<0<<endl;}//狗东西!非负是吧,真恶心!
    for(auto r=yinzi.begin();r!=yinzi.end();r++){
        int i=1;
        int cnt=0;
        for(;i<=n;i++){
            if(sum[i]-tm>*r)break;
            if(sum[i]-tm==*r){
                tm=sum[i];
                cnt++;
            }
        }
        if(i>=n&&sumx/cnt==*r){
            cout<<*r<<endl;
            break;
        }
        tm=0;
    }
}