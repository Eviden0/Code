#include<iostream>
#include<cmath>
#include <complex>

using namespace std;
bool isPerfectSquare(long long num) {
    int x = sqrt(num);
    return x * x == num;
}

bool check(int a1[3],int a2[3],int a3[3],int eg){
    for(int i=1;i<=2;i++){
        if(a1[i]>eg||a2[i]>eg)return false;
        else {
            int lef=0;
        // 1 4
        // 1 4
        // 2 4
        if(a1[i]==eg&&a2[1]==eg){
            if(i==1){
                //a1[2] + a2[2]
                lef=eg-a1[2]-a2[2];
            }else {lef=eg-a1[1]-a2[2];}
        }else if(a1[i]==eg&&a2[2]==eg){
            if(i==1){
                //a1[2] + a2[2]
                lef=eg-a1[2]-a2[1];
            }else {lef=eg-a1[1]-a2[1];}
        }else if(a1[i]+a2[1]==eg){
            if(i==1){
                //只能是两个方型!
                lef=eg-a1[2]-a2[1];
            }
        }
        else if(a1[i]+a2[2]==eg){

        }
                // if(a1[i]==eg||a2[j]==eg||a1[i]+a2[j]==eg){

                // }
            
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int edge[3][3]={0};
        long long sum=0;
        int mm=-1;
        // 1 4
        // 1 4
        // 2 4
        for(int i=1;i<=2;i++){
            cin>>edge[i][1]>>edge[i][2];
            sum+=(edge[i][1]*edge[i][2]);
        }
        if(!isPerfectSquare(sum)){
            cout<<"NO\n";
            break;
        }
        else{
            int sq=sqrt(sum);
            check(edge[1],edge[2],edge[3],sq);


        }
    }
}