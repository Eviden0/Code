#include "iostream"
#include <cmath>
using namespace std ;
double n;
bool check (double x)
{
    if(x*x*x<=n){
        return true ;
    }
    else {
    return false;
    }
}
int main()
{
    scanf("%d",&n);
    double l=-100,r=100;
    //while(r-l>1e-8)//这里是一个不好的写法,控制精度不够
    //直接用100次二分得到足够的精度
    for (int i=1;i<=100;i++) {
        double mid = (l+r)/2;
        if(check(mid)){
            l=mid; 
        }
        else {
        r=mid;
        }
    }
    printf("%lf\n",l); 
    // printf("%lf\n",r);
   return 0;
}
