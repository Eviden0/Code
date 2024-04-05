#include<iostream>

using namespace std;
bool check(int index,int tar){
    if(index<tar)return true ;
    else return false;
}
int binary_search(int n[],int size,int tar){
    int left = 0,right = size+1;
    while(left+1<right){
        int mid=(left+right)/2;
        if(check(n[mid],tar)){
            left=mid;
        }else right=mid;
    }
    if(n[right]==tar)return right;
    else return -1;
}
int num[10000010],tar[100010];
int main(){
    int n,m;cin>>n>>m; 
    for(int i=1;i<=n;i++)scanf("%d",&num[i]);
    for(int i=1;i<=m;i++)scanf("%d",&tar[i]);
    //序列中第一次出现的编号,并不是简单粗暴的二分查找
    for(int i=1;i<=m;i++){
        // if(binary_search(num,n,tar[i]))printf("%d\n",i);
    printf("%d ",binary_search(num,n,tar[i]));
    }
}