#include<iostream>
using namespace std;
const int N=10;
bool st[N];
int arr[N];
int n;
void dfs(int x){
    //搜到大于n位的就说明全部枚举完了
    if(x>n){
        for(int i=1;i<=n;i++){
            printf("%5d",arr[i]);//输出场宽为5,没有5位用空格补齐5位
        }
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i]=true;
            arr[x]=i;
            dfs(x+1);//递归开搜
            st[i]=false;
            arr[x]=0;
        }
    }
}
int main(){
cin>>n;
dfs(1);
}