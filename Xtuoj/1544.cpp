#include <bits/stdc++.h>
using namespace std;
priority_queue<int> max_top;
priority_queue<int, vector<int>, greater<int>> min_top;
char s[6];

void eval()
{
    if (max_top.size() - 1 > min_top.size())
    {
        // 重新平衡一下堆
        min_top.push(max_top.top());
        max_top.pop();
    }
    if (max_top.size() < min_top.size())
    {
        max_top.push(min_top.top());
        min_top.pop();
    }
}
void push(int tn)
{

    // 首先压入maxtop
    // if (tn <= max_top.top() || max_top.empty()) // 第一次队列啥都没有,访问空会异常
    if (max_top.empty() || tn < max_top.top())
    {
        max_top.push(tn);
    }
    else
        min_top.push(tn);
    eval();
}

int main()
{
    while (scanf("%s", s) != EOF)
    {
        /* code */
        if (s[1] == 'u')
        {
            int n;
            scanf("%d", &n);
            push(n);
        }
        else
        {
            printf("%d\n", max_top.top());
            max_top.pop();
            // eval();
            if (max_top.size() < min_top.size())
            {
                max_top.push(min_top.top());
                min_top.pop();
            }
        }
    }
}