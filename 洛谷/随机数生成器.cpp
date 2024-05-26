#include <bits/stdc++.h>
using namespace std;
int rand_num(int l, int r)
{

    // 返回l 到 r+l-1的随机数(左闭右闭)
    r = r - l + 1;
    return (rand() % r + l);
}
int main()
{

    // cout << "RAND_MAX:" << RAND_MAX << endl;
    // srand((unsigned)time(NULL));
    // for (int i = 0; i < 5; i++)
    //     cout << (rand() % 3) << " "; // 生成[0,1]范围内的随机数
    // cout << endl;
    // for (int i = 0; i < 5; i++)
    //     cout << (rand() % 5 + 3) << " "; // 生成[3,7]范围内的随机数
    // cout << endl;
    int t = 10;
    srand((unsigned)time(NULL)); // 引入随机数种子
    while (t--)
        cout << rand_num(1, 10) << ' ';
}