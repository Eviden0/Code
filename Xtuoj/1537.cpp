#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum[10010] = {0};
        // , a[10010] = {0};
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            sum[i] = sum[i - 1] + a; // 求出前缀和
        }
        for (int i = 1; i < 1000000; i++)
        {
            // 二分搜索!
        }
    }
}