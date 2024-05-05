#include<iostream>
using namespace std;
//对特定格式的数据进行输入时
//可以利用scanf的判断进行输入
//遇到求时间之间的差的时候统一为s来做
//再统一回去
int solve(){
    int h1,m1,s1,h2,m2,s2,day=0;
    scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
    if(getchar()==' ')scanf("(+%d)",&day);
    return (day*86400+h2*3600+m2*60+s2)-(h1*3600+m1*60+s1);
}
string s1;
// string time[1000];
int main(){
    int n;
    cin>>n;
    while (n--)
    {
        int ans=(solve()+solve())/2;
        printf("%02d:%02d:%02d\n",ans/3600,ans%3600/60,ans%60);
    }
    return 0;
    
}