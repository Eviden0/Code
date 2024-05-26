#include <bits/stdc++.h>
using namespace std;
stack<int> p, q; // q是保存最小值的栈
/*
同步保持q栈是p栈压入数据时的最小值!
弹出时也可同时弹出
*/

int rand_num(int l, int r)
{
    // 返回l 到 r+l-1的随机数
    r = r - l + 1;
    return (rand() % r + l);
}
void push(int x)
{
    if (p.empty() || q.empty())
    {
        p.push(x), q.push(x);
    }
    else
    {
        if (x <= q.top())
        {
            q.push(x);
            p.push(x);
        }
        else
        {
            p.push(x);
            q.push(q.top());
        }
    }
}
void prin(stack<int> &q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
}
int main()
{
    srand((unsigned)time(NULL)); // 引入随机数种子
    int t = 10;
    while (t--)
    {
        push(rand_num(1, 10));
    }
    cout << "p栈的情况: " << endl;
    prin(p);
    cout << endl;
    cout << "q栈的情况: " << endl;
    prin(q);
}