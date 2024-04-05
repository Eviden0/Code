#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;


int main(){
    int T;cin>>T;
    while (T--)
    {   
        // 最终情况是除10等于0
        
        // char num[10]={'0'};
        // scanf("%s",num);
        string num;
        int result,cnt=0;
        cin>>result;
        num=to_string(result);
        while (result/10!=0)
        {   
            // for(int i=0;num[i]!='\0';i++){
            // // printf("%c",num[i]);
            // cout<<num[i]-'0'<<' ';
            string ji,ou;
            for(int i=0;i<num.size();i++){
                if(i%2==0)ou+=num[i];
                else ji+=num[i];
            }
            result=stoi(ou)*stoi(ji);
            // cout<<ou<<' '<<ji<<' '<<result<<endl;
            num=to_string(result);
            // break;
            cnt++;
        }
          cout<<cnt<<endl;
        }
      
      
    }
    