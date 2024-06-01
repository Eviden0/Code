#include <bits/stdc++.h>
using namespace std;
int main()
{

    // 二分计算 根号3
    // 注意锁精度
    double l = 0, r = 1e9;
    while (r - l > 1e-13)
    {
        double mid = (l + r) / 2;
        if (mid * mid >= 3)
            r = mid;
        else
            l = mid;
    }
    // cout << setprecision(13) << r << endl;
    double x, y;
    cin >> x >> y;
    cout << fixed << setprecision(6) << (x / 2 + y / 2) << ' ' << fixed << setprecision(6) << (r / 2.0 * (x - y)) << endl;
}