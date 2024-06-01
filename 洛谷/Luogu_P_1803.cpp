#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{

    int n;
    cin >> n;
    // 求的是 尽量选择 不能相交区域的线段最大段数
    // 0-2 2-4 1-3
    // 选0-2 2-4
    // vector<int> a(n);
    vector<pair<int, int>> aa(n);
    pair<int, int> mm;
    mm.second = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> aa[i].first >> aa[i].second;
        // if (aa[i].second < mm.second)
        // {
        //     mm.first = aa[0].first;
        //     mm.second = aa[0].second;
        // }
    }
    // 排序时根据结束时间来排,贪心就是右边越往左越好!
    sort(aa.begin(), aa.end(), cmp);
    mm.first = aa[0].first;
    mm.second = aa[0].second;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (aa[i].first >= mm.second)
        {
            ans++;
            mm.second = aa[i].second;
        }
        // cout << aa[i].first << ' ' << aa[i].second << endl;
    }
    cout << ans;
    // cout << mm.first << ' ' << mm.second << endl;
}