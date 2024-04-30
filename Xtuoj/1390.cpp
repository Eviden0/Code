#include<iostream>

using namespace std;
    string s;
    int arr[27];
void dfs(int x){
    int cnt=0;
    if(s[x]=='('){
        dfs(x+1);
    }
    else if(s[x]==')'){

    }
    else if(s[x]>='a'&&s[x]<='z'){
        arr[s[x]-'a']++;
        while(s[x+1]>='0'&&s[x+1]<='9'){
            // arr[s[x+1]-'a']+=;
    }
    }
    dfs(x+1);
}
int main(){

    cin>>s;
    
}