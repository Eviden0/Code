// 给出 前序遍历 和 中序遍历
// 求出后序遍历
// 一定要看清题目中为先中序，再是前序
#include <bits/stdc++.h>
using namespace std;
string a, b;
// x ,y搜前序,p,q搜后序
void dfs(int x, int y, int p, int q)
{
    if (x > y || p > q)
        return; // 不存在子树,退出递归
    else
    {
        int i = b.find(a[x]);
        dfs(x + 1, x + i - p, p, i - 1); // 搜左
        dfs(x + i - p + 1, y, i + 1, q); // 搜右
        cout << a[x];                    // 最后输出根
    }
}
int main()
{
    cin >> b >> a;
    int l = a.length() - 1;
    dfs(0, l, 0, l);
}