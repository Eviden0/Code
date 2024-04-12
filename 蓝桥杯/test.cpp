#include<bits/stdc++.h>
using namespace std;
int n,m,a[8],s=0;
void dfs(int k)//分第k份 
{
	if(n==0)return ;
	if(k==m)
	{
		if(n>=a[k-1])s++;
		return;
	}
	for(int i=a[k-1];i<=n/(m-k+1);i++)//第k份的上下界 
	{
		a[k]=i;//第k份的值 
		n-=i;
		dfs(k+1);
		n+=i;
	}
}
int main()
{
	cin>>n>>m;
	a[0]=1;//初始条件 
	dfs(1);
	cout<<s<<endl;
	return 0;
}
