#include <bits/stdc++.h>

using namespace std;

int minTimeToCompleteTasks(const vector<int> &a, const vector<int> &b)
{
    int n = a.size();
    int totalA = accumulate(a.begin(), a.end(), 0);
    vector<vector<int>> dp(2, vector<int>(totalA + 1, INT_MAX));

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= totalA; ++j)
        {
            dp[i % 2][j] = INT_MAX;
            if (j >= a[i - 1] && dp[(i - 1) % 2][j - a[i - 1]] != INT_MAX)
            {
                dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][j - a[i - 1]]);
            }
            if (dp[(i - 1) % 2][j] != INT_MAX)
            {
                dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][j] + b[i - 1]);
            }
        }
    }

    int result = INT_MAX;
    for (int j = 0; j <= totalA; ++j)
    {
        result = min(result, max(j, dp[n % 2][j]));
    }

    return result;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        printf("%d\n", minTimeToCompleteTasks(a, b));
    }

    return 0;
}
