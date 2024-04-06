#include<iostream>

using namespace std ;
double a,b,c,d;
bool check(double l,double r){
    //maybe is 零点存在定理
    //0.01 0.02 0.03 x 0.04 0.05 0.06
    if( (a*l*l*l + b*l*l + c*l + d)*(a*r*r*r+b*r*r+c*r+d)<=0){
        return true;
    }
    else return false;
}
double cal(double l){
    return a*l*l*l + b*l*l + c*l + d;
}

int main(){

    cin>>a>>b>>c>>d;
    double l=-100,r=100;
    int cnt=0;//找到3个解直接退出
    for(int i=-100;i<100;i++){
    l=i;
    r=i+1;
    double r1=cal(l),r2=cal(r);
    if(!r1){
        printf("%.2lf ",l);
        cnt++;
    }
    double mid;
    if(r1*r2<0)
    {   
     while(r-l>=0.001){
        mid = (l+r)/2;
        if(cal(mid)*cal(r)<=0)l=mid;
        else r=mid; 
    }
    printf("%.2lf ",mid);
    cnt++;
    }
    if(cnt==3)break;

    }
}