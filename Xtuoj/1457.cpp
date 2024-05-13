#include<iostream>
#include<cmath>
using namespace std;
long long x,y;
void find(int n,long long k){
	if(!n)return;
	else {
	long long child_bar=pow(2,2*(n-1));
	int i;
	for(i=1;i<=4;i++){
	//找到子块,那就减去之前i-1个子块的!
	//只到第i个子块里面找!
		if(i*child_bar>=k){
			k-=(i-1)*child_bar;
			break;
		}
	}
		//扫描四个子块,左->右,上->下
		//对应坐标偏移(0,0),(0,1),(1,0),(1,1)
		child_bar=pow(2,n-1);
		if(i==2)y+=child_bar;
		else if(i==3)x+=child_bar;
		else if(i==4){x+=child_bar,y+=child_bar;}
		find(n-1,k);
	}
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		//记得初始化!
		x=y=1;
		int n;
		long long k;cin>>k;
		for(int i=0;i<61;i++){
			long long kuai=pow(2,2*i);//查找总查询次数
			if(kuai>=k){
				n=i;break;
			}
		}
		find(n,k);
		cout<<x<<' '<<y<<endl;
		// printf("%I64d %I64d\n",x,y);
	}
}