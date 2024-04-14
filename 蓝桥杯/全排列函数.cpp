#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int cmp(int x,int y){return x>y;};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int arr[]={1,2,3};
    sort(arr,arr+3,cmp);
    do{
         cout << arr[0] << ' ' << arr[1] << ' ' << arr[2]<<'\n';
    }
    while (prev_permutation(arr,arr+3));
    

}