#include <bits/stdc++.h>

using namespace std;
int n;
int minTimeToCompleteTasks(const vector<int> &a, const vector<int> &b)
{
    // int n = a.size();
    int totalA = accumulate(a.begin(), a.end(), 0);

    // 使用滚动数组优化，只保留上一行的信息
    vector<int> dp(totalA + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        vector<int> next_dp(totalA + 1, INT_MAX);
        for (int j = 0; j <= totalA; ++j)
        {
            if (j >= a[i - 1] && dp[j - a[i - 1]] != INT_MAX)
            {
                next_dp[j] = min(next_dp[j], dp[j - a[i - 1]]);
            }
            if (dp[j] != INT_MAX)
            {
                next_dp[j] = min(next_dp[j], dp[j] + b[i - 1]);
            }
        }
        dp = move(next_dp); // 将下一行的信息移动到当前行
    }

    int result = INT_MAX;
    for (int j = 0; j <= totalA; ++j)
    {
        result = min(result, max(j, dp[j]));
    }

    return result;
}

int main()
{

    // vector<int> a = {1, 2, 3};
    // vector<int> b = {3, 2, 1};
    int t;
    scanf("%d", &t);
    while (t--)
    {

        scanf("%d", &n);
        vector<int> a(1005);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        vector<int> b(1005);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        // cout << "Minimum time to complete all tasks: " << minTimeToCompleteTasks(a, b) << endl;
        printf("%d\n", minTimeToCompleteTasks(a, b));
    }

    return 0;
}
