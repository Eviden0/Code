#include<bits/stdc++.h>
using namespace std;
int s1[100010],s2[100010];

bool is_sorted(int *a,int size){
    for(int i=0;i<size-1;i++)
    if(a[i]>a[i+1])return false;
    return true;
}


//升序!
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
       int x;cin>>x;
        s1[i]=x,s2[i]=x;
    }
    sort(s2,s2+n);
    // for(int i=0;i<n;i++)cout<<s1[i]<<' ';
    // cout<<endl;
    for(int i=0;i<n;i++){
        if(s2[i]-s1[i]!=0){
            int tm=s1[i];
            s1[i]=s1[n-i-1];
            s1[n-i-1]=tm;
        }
    }
    // for(int i=0;i<n;i++)cout<<s1[i]<<' ';
    if(is_sorted(s1,n))cout<<"YES";
    else cout<<"NO";
}