#include <bits/stdc++.h>

using namespace std;
bool cmt(int a, int b) { return a > b; }
long long m(int h1, int h2)
{
    return (h1 - h2) * (h1 - h2);
}
int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    // a.push_back(0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), cmt);

    // for (int i : a)
    //     cout << i << " ";
    // 排序中间回环跳法
    // 6 5 4 3
    // 0->6->3->5->4
    int i = 0, j = n - 1, last = 0;
    long long ans = 0;
    bool flag = true; // 判断是左还是右
    while (1)
    {
        if (flag)
        {
            // 先左
            ans += m(a[i], last);
            last = a[i];
            i++;

            flag = 0;
        }
        else
        {
            ans += m(a[j], last);
            last = a[j];
            j--;

            flag = 1;
        }
        if (i > j)
            break;
    }
    cout << ans;
}