#include<iostream>

using namespace std;
//其实本题就是一个fib数列问题呗
//只不过数据量大点,ok那我们手动实现一下求fib 第 100 项
//递推关系      fn=fn-1+fn-2
int fib(int n){
    if(n==1||n==2)return 1;
    else return fib(n-1)+fib(n-2);
}
int main(){
    int a,b;cin>>a>>b;
    cout<<fib(b+1-a);
}




#include<cstdio>
using namespace std;
int n,m,t;
bool pd=0;
int a[1001][601];
int main()
{
	scanf("%d%d",&m,&n);
	t=n-m;
	a[0][1]=0;
	a[1][1]=1;
	a[2][1]=2;
	for(int i=3;i<=t;i++)
	{
		for(int j=1;j<600;j++) 
		a[i][j]=a[i-1][j]+a[i-2][j];
		for(int j=1;j<600;j++)
		{
			while(a[i][j]>9)
			{
				a[i][j+1]++;
				a[i][j]-=10;
			}
		}
	}
	for(int i=600;i>1;i--)
	{
		if(!pd&&a[t][i]==0)continue;
		pd=1;printf("%d",a[t][i]);
	}
	printf("%d",a[t][1]);
	return 0;
}