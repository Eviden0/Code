// 1 1 2
// 2 2 =>2+2+2 =6
// 1 3 => 1+3+3 =7
// 每次都只能取队列中的最小值
#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    long long ans = 0;
    // cout << pq.top();
    n -= 1;
    while (n--)
    {
        int x1 = pq.top();
        pq.pop();
        int x2 = pq.top();
        pq.pop();
        ans += x1 + x2;
        pq.push(x1 + x2);
    }
    cout << ans;
}