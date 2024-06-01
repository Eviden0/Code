#include <bits/stdc++.h>

using namespace std;
int main()
{
    int w, n;
    cin >> w >> n;
    vector<int> a(n);
    // 分组少,也就是尽量把能分2个一组的全分了
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int twogifts = 0;
    for (int i = 0, j = n - 1; i < j;)
    {
        if (a[i] + a[j] <= w)
        {
            i++;
            j--;
            twogifts++;
        }
        else
        {
            j--;
        }
    }
    int ans = twogifts + (n - twogifts * 2);
    cout << ans;
}