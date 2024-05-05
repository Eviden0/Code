#include<bits/stdc++.h>

using namespace std;
int arr[10010];
int huocai[10010]={6,2,5,5,4,5,6,3,7,6};
int n,cnt=0;
int cal(int n){
    int tn=n;
    //可以优化这个cal,用数组给他存住
    //即 记忆化搜索
    int s=0;
    if(huocai[n]>0){return huocai[n];}
    else{ 
        while(n){
        s+=huocai[n%10];
        n/=10;
    }
    huocai[tn]=s;
    return s;
    }
}
void dfs(int index,int sum){
    if(sum>n)return ;
    if(index>3){

    if(arr[1]+arr[2]==arr[3]&&sum==n){
        cnt++;
    }
    return ;
    }
    for(int i=0;i<=1000;i++){
        arr[index]=i;
        dfs(index+1,sum+cal(i));
        arr[index]=0;
    }
}
int main(){
    //先用递推算出来,避免后面重复算
    for(int i=10;i<=1000;i++){
        huocai[i]=huocai[i%10]+huocai[i/10];
    }
    cin>>n;
    n-=4;
    dfs(1,0);
    cout<<cnt;
    return 0;
}