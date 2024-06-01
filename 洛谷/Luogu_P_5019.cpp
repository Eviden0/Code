#include <bits/stdc++.h>
using namespace std;
int main()
{
    // f[i]
    // 4 0 0 3 0 2

    int n;
    cin >> n;
    int a[100005] = {0};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            ans += a[i] - a[i - 1];
    }
    cout << ans;
}