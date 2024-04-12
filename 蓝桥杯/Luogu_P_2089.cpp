// #include<bits/stdc++.h>
// using namespace std;

// int arr[31],n,k=10,cnt=0;
// //先存所有方案到数组
// int res[59555][11];
// int sum;
// void dfs(int index,int sum){
//     if(sum>n)return ;
//     if(index>10){
//         if(sum==n){
//             cnt++;
//             for(int j=1;j<=10;j++)res[cnt][j]=arr[j];
//             // cout<<endl;
//         }
//         return ;
//     }
//     for(int i=1;i<=3;i++){
//         arr[index]=i;
//         dfs(index+1,sum+i);
//         arr[index]=0;
//     }
// }
// int main(){
// cin>>n;
// dfs(1,0);
// cout<<cnt<<endl;
// for(int i=1;i<=cnt;i++){
//     for(int j=1;j<=10;j++)cout<<res[i][j]<<' ';
//     cout<<endl;
// }
// return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int res[12][12],arr[12];
int n=10,sum,cnt=0;
void dfs(int x,int s){
    if(s>sum)return;
    if(x>n){
        if(s==sum){
            cnt++;
            for(int i=1;i<=n;i++)res[cnt][i]=arr[i];
        }
        return;
    }
    for(int i=1;i<=3;i++){
        arr[x]=i;
        dfs(x+1,s+i);
        arr[x]=0;
    }
}
int main(){
    cin>>sum;
    dfs(1,0);
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=10;j++)cout<<res[i][j]<<' ';
        cout<<endl;
    }
}   