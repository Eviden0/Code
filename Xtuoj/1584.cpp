#include<iostream>
#include<queue>
using namespace std;

// 一个数列a1,a2,…,an，每次你选择执行以下两个操作之一:
// 取数列中最小的两个数，将两者差的绝对值，再加入数列；
// 取数列中最大的两个数，将两者差的绝对值，再加入数列；
// 进行n-1 次操作之后是否只剩下一个元素0

//本题关键 是如何同时取得最大最小,试试双端队列咯!

//2 
//1 1
int main(){
int t;
scanf("%d",&t);
while (t--)
{
    priority_queue<int> q;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int tm;
        scanf("%d",&tm);
        q.push(tm);
    }
    int cnt=n-1;
    while(cnt--){
        int tm=q.top();
        q.pop();
        tm=abs(tm-q.top());
        q.pop();
        q.push(tm);
    }
    if(q.size()==1){
    if(q.top()==0){printf("Yes\n");}
    else printf("No\n");
    }
    else printf("No\n");
}

}