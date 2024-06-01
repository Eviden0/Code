#include <bits/stdc++.h>

using namespace std;
int main()
{
    double n, t;
    // t为总容量
    cin >> n >> t;

    unordered_map<double, double> a;
    priority_queue<double> b;
    for (int i = 0; i < n; i++)
    {
        double x1, x2;
        cin >> x1 >> x2;
        // 指定保存两位小数
        a[x2 / x1] = x1;
        b.push(x2 / x1);
    }
    double ans = 0;
    while (!b.empty() && t)
    {
        // 一次直接拿完
        if (a[b.top()] <= t)
        {
            ans += b.top() * a[b.top()];
            t -= a[b.top()];
            b.pop();
        }
        else
        {
            // 拿不完
            ans += t * b.top();
            t = 0;
        }
    }
    // 输出两位小数
    cout << fixed << setprecision(2) << ans;
}