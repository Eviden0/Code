#include<iostream>
#include<cstring>
using namespace std;
// string s;
char s[51];
void dfs(int l,int r,long long *c){
    long long c1[27]={0},c2[27]={0};
    int tl;
    int p;
    // cout<<s[l];
    if(s[l]=='('){
        tl=l;//匹配右括号
        int cnt=0;
        while(1){
            if(s[tl]=='(')cnt++;
            else if(s[tl]==')')cnt--;
            if(!cnt)break;
            tl++;
        }
        // tl--;
        // cout<<tl<<endl;
        // tl++;
        dfs(l+1,tl-1,c1);
        long long num_bei=0;
        int i;
        for(i=tl+1;i<=r;i++){
            //取数字
            if(s[i]>='0'&&s[i]<='9')num_bei=num_bei*10+(s[i]-'0');
            else break;
        }
        p=i-1;
        for(int j=0;j<=26;j++)c1[j]*=num_bei;
    }
    else {
        long long num_bei=0;
        int i;
        for(i=l+1;i<=r;i++){
            if(s[i]>='0'&&s[i]<='9')num_bei=num_bei*10+(s[i]-'0');
            else break;
        }
        p=i-1;
        // cout<<"l+1: "<<l+1<<" tl:"<<tl<<endl;
        //没动,说明默认为1
        if(i==l+1)num_bei=1;
        //加到对应的数组值里面
        c1[s[l]-'a']+=num_bei;
    }

    if(p+1<=r)dfs(p+1,r,c2);
    //合并
    for(int i=0;i<27;i++){
        c[i]=c1[i]+c2[i];
    }
}
int main(){
    
    while(scanf("%s",s)!=EOF){
        long long ans[27]={0};
        dfs(0,strlen(s)-1,ans);
        //if(ans[i])cout<<(char)(i+'a')<<" : "<<ans[i]<<endl;
        for(int i=0;i<27;i++)if(ans[i])printf("%c : %d\n",i+'a',ans[i]);
        printf("\n");
    }
}