// #include <bits/stdc++.h>
// using namespace std;
// // 递推方法
// int main()
// {
//     // 1-n 可能通过栈的两种操作后结果的输出数量
//     //     建立数组f。f[i]表示i个数的全部可能性。

//     // f[0] = 1, f[1] = 1; //当然只有一个

//     // 设 x 为当前出栈序列的最后一个，则x有n种取值

//     // 由于x是最后一个出栈的，所以可以将已经出栈的数分成两部分
//     // 比x小的数有x-1个，所以这些数的全部出栈可能为f[x-1]
//     //
//     // 比x大的数有n-x个，所以这些数的全部出栈可能为f[n-x]
//     int n;
//     cin >> n;
//     // 1-n
//     vector<int> f(n + 1);
//     f[0] = f[1] = 1;
//     long long ans = 0;
//     for (int i = 2; i <= n; i++)
//     {
//         // f[i]表示 i 个数的可能性
//         for (int j = 0; j < i; j++)
//         {
//             f[i] += f[j] * f[i - j - 1];
//         }
//     }
//     cout << f[n];
// }

// 记忆化搜索!
#include <iostream>
using namespace std;

long n, f[20][20];
long dfs(int x, int y)
{
    if (f[x][y])
        return f[x][y];
    if (x == 0)
        return 1;
    if (y > 0)
        f[x][y] += dfs(x, y - 1);
    f[x][y] += dfs(x - 1, y + 1);
    return f[x][y];
}
int main()
{
    int n;
    cin >> n;
    cout << dfs(n, 0);
}