#include<iostream>

#include<string>
using namespace std;

int main(){
        int zom[26]={0};
        /* code */
        int k;cin>>k;
        while (1)
        {
            char a=getchar();
            if(a=='\n')break;
            zom[a-'a']++;
            /* code */
        }
        for(int i=0;i<26;i++)cout<<zom[i]<<' ';
}