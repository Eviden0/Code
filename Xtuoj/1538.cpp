#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while (cin>>s)
    {
        string tar;
        int index=0;
        for(int i=0;i<s.size();i++){
            switch (s[i])
            {
            case '[':
                /* code */
                index=0;
                break;
            case ']':
                /* code */
                index=tar.size();
                break;
            case '<':
                /* code */
                if(index!=0)index--;
                break;
            case '>':
                /* code */
                if(index!=tar.size())index++;
                break;
            case '+':
                /* code */
                if(index!=tar.size()){tar.erase(tar.begin()+index);}
                break;
            case '-':
                /* code */
                if(index!=0){tar.erase(tar.begin()+index-1);index--;}
                break;
            default:
                tar.insert(index,1,s[i]);
                index++;
                break;
            }
            // 202205501919.
        }
        cout<<tar<<endl;
    }
}
