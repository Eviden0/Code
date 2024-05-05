#include<iostream>

using namespace std;
char tar[110][110];
int main(){
int m,n;cin>>n>>m;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)cin>>tar[i][j];
}
for(int i=1;i<=n;i++){
    // cout<<tar[i]<<endl;
    for(int j=1;j<=m;j++){
        // cout<<tar[i][j];
        /*
        top -> tar[i-1][j]
        left -> tar[i][j-1]
        right -> tar[i][j+1]
        down -> tar[i+1][j]
        tar[i-1][j-1]
        tar[i-1][j+1]
        tar[i+1][j-1]
        tar[i+1][j+1]
        */
        int sum=0;
        if(tar[i][j]=='*'){cout<<'*';continue;}
        else {
                if(tar[i][j-1]=='*')sum++;
                if(tar[i-1][j]=='*')sum++;
                if(tar[i][j+1]=='*')sum++;
                if(tar[i+1][j]=='*')sum++;
                if(tar[i-1][j-1]=='*')sum++;
                if(tar[i-1][j+1]=='*')sum++;
                if(tar[i+1][j-1]=='*')sum++;
                if(tar[i+1][j+1]=='*')sum++;
        }
        cout<<sum;
    }
    cout<<endl;
}
}