#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < n; i++)
    {
        // int x1, x2;
        // cin >> x1 >> x2;
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    int cost = 0;
    for (auto i : a)
    {
        // cout << i.first << " " << i.second << endl;
        if (i.second <= n)
        {
            // 一次买完奶牛的奶
            cost += i.first * i.second;
            n -= i.second;
        }
        else
        {
            // 买不完
            cost += i.first * n;
            break;
        }
    }
    cout << cost;
}