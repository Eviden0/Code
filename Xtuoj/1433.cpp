#include <iostream>
#include <vector>

using namespace std;

// 计算阶乘
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// 计算排列数
int permutation(int n, int m) {
    return factorial(n) / factorial(n - m);
}

int countNumbersWithUniqueDigits(int n, int k) {
    if (k == 0) return 1; // 当k为0时，只有一个数，即0
    if (n == 0) return 0; // 当n为0时，不存在不含前导0的数
    if (n == 1) return 9; // 当n为1时，不含前导0的数为1到9共9个
    if (k > n - 1) k = n - 1; // 最多只能交换n-1次

    // 动态规划求解
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[1][0] = 1; // 只有一个数码时，不管交换次数，结果都是1
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = 9 * permutation(9, i - 1); // 没有交换时，结果为9 * 9!
        for (int j = 1; j <= min(k, i - 1); ++j) {
            dp[i][j] = dp[i - 1][j] * (i - 1) + dp[i - 1][j - 1] * (10 - i + 1);
        }
    }

    int result = 0;
    for (int j = 0; j <= k; ++j) {
        result += dp[n][j];
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k; // 输入n和k
    cout << countNumbersWithUniqueDigits(n, k) << endl; // 输出结果
    return 0;
}
