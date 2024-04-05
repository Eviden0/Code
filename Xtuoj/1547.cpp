#include<iostream>

using namespace std;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main(){
//-----result=r/2*(r+h)
int T;cin>>T;
while (T--)
{
    /* code */
    int r,h;cin>>r>>h;
    int r1=r,r2=2*(r+h),gn=gcd(r1,r2);
    printf("%d/%d\n",r1/gn,r2/gn);

}

}
