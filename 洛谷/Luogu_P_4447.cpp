#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    // if (a > 0 || b > 0)
    return a < (b);
}
int main()
{
    priority_queue<int, vector<int>, greater<int>> q;
    // 输出人数最少的组人数的最大值
    // 于是要求分成的每个小组的队员实力值连续，
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    // for (int i : a)
    //     cout << i << ' ';
    // cout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        int cnt = 1;
        while (a[i] + 1 == a[i + 1] && i < n - 1)
        {
            i++;
            cnt++;
        }
        q.push(cnt);
        // i++;
    }
    cout << q.top();
}