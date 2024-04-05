#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(const int &a,const int &b)
{
		return a > b;//从大到小 
        //或者b<a也行 
}
bool isSameAll(int n){
    string s=to_string(n);
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[0])return false;
    }
    return true;
}
int main(){
    int T;cin>>T;
    while (T--)
    {
        /* code */
        //1990 
        //0199 + 9910   ->  0109  0019 +9100
        string num;cin>>num;
        int cnt=0,result=stoi(num);
        while (1)
        {
            if(isSameAll(result))break;
            /* code */
            sort(num.begin(),num.end(),cmp);
            string da=num;
            sort(num.begin(),num.end());
            string xiao=num;
            result=stoi(xiao)+stoi(da);
            num=to_string(result);
            num=num.substr(num.size()-4,num.size());
            result=stoi(num);
            cnt++;
            
        }
        cout<<cnt<<endl;
    }
    
}