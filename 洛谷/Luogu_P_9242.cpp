#include<bits/stdc++.h>
using namespace std;

int dp[15];
string s;

int main(){      
    ios::sync_with_stdio(false);
    //先求最长接龙序列,再减
    int n;cin>>n;
    int maxx=-1;
    for(int i=1;i<=n;i++){
  
        cin>>s;
        // dp[i]=1;
        int m=s.size();
        // cout<<s[m-1]-48<<endl;
        // cout<<s[0]-48<<endl;
        // cout<<"---"<<endl;
        dp[s[m-1]-48]=max(dp[s[m-1]-48],dp[s[0]-48]+1);
        // dp[s[m-1]-'0']=max(dp[s[m-1]-'0'],dp[s[0]-'0']+1);
        // maxx=max(dp[i],maxx);
    }
    // int maxx=-1;
    for(int i=0;i<9;i++)maxx=max(dp[i],maxx);
    cout<<n-maxx;
}

// #include<bits/stdc++.h>
// using namespace std;
// char s[15];int dp[15];
// int main(){
// 	int n,cnt=0;scanf("%d",&n);
// 	for(int i=1;i<=n;i++){
// 		scanf("%s",s);int m=strlen(s);
// 		dp[s[m-1]-48]=max(dp[s[m-1]-48],dp[s[0]-48]+1);
// 	}
// 	for(int i=0;i<10;i++) cnt=max(cnt,dp[i]);
// 	printf("%d",n-cnt);
// 	return 0;
// }
