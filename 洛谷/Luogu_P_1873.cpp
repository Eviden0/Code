#include<iostream>

using namespace std;
int num[1000010];
long long sum_tree(int n[],int size,int x){
    long long sum=0;//不开long long见祖宗!
    for(int i=1;i<=size;i++){
        int result = n[i]-x;
        if(result>0)sum+=result;
        else continue;
    }
    return sum;
}
//n表示树的数量,m表示需要木材的总长度
//第二行,树的长度

/*
求最终的高度
满足 sum(树-高度)==m
400000 log2 400000 =18
找到最大的满足每颗树砍的高度 即返回l
*/
int main(){
    long long n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>num[i];
    // long long sum=0;
    int l=0,r=400010,mid;
    for(int i=0;i<21;i++){
         mid=(r+l)>>1;
        //  cout<<mid<<' '<<sum_tree(num,n,mid)<<endl;
            if(sum_tree(num,n,mid)<m){
                r=mid;
            }else{
                l=mid;
            }
    }
    cout<<l;
    // }if(sum_tree(num,n,mid)<m){cout<<l;}
}