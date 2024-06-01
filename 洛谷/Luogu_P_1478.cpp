#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    vector<pair<int, int>> apple(n);
    for (int i = 0; i < n; i++)
    {
        cin >> apple[i].first >> apple[i].second;
    }
    sort(apple.begin(), apple.end(), cmp);
    int ans = 0;

    for (auto i : apple)
    {
        // break;
        // cout << s << endl;
        // cout << i.first << ' ' << i.second << endl;
        if (i.second > s)
            break;

        if (i.first <= a + b)
        {
            // 选
            ans++;
            s -= i.second;
        }
    }
    cout << ans;
}