#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, x;
    cin >> n >> x;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    long long ans = 0;
    if (num[0] > x)
    {
        ans += num[0] - x;
        num[0] -= (num[0] - x);
    }
    for (int i = 1; i < n; i++)
    {
        if ((num[i - 1] + num[i]) > x)
        {
            ans += (num[i] + num[i - 1] - x);
            num[i] -= (num[i] + num[i - 1] - x);
        }
    }
    // for (int i : num)
    //     cout << i << " ";
    cout << ans;
}