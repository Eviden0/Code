#include<iostream>
#include <algorithm>
#include<cmath>

using namespace std;

string t1,t2,g;
// int b[100005];
//给出153
//即用1 5 3 三个数字构成两个数相乘 到等于 153
//平方根为12

void solve(int n){

    // 我们将n的数码中取出一个作为数x
    for(int i=2;i<10;i++){
        //61 2 16 2
        if(n%i==0){
            string s=to_string(n);
            // if(g.find(s)!=-1)
            string tm=s;
            sort(s.begin(),s.end());
            t1=to_string(i);
            if(s.find(t1)==-1)continue;
            t2=to_string(n/i);
            sort(t1.begin(),t1.end());
            sort(t2.begin(),t2.end());
            s.erase(s.find(t1),t1.size());
            // cout<<"numis:"<<n<<' '<<t1+' '<<s<<' '<<t2<<endl;
            
            if(s==t2)
            {
            // cout<<"因子:"<<t1<<' '<<t2<<' '<<n<<endl;
            // cout<<n<<endl;
            // g+=(tm+'+');

            printf("%d\n",n);
            break;
            }
           
        }
        continue;
    }
}

int main(){
    // int a=153;
    // 899020
    for(int i=126;i<791290;i++){
        solve(i);
    }
}

