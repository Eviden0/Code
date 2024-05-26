#include <bits/stdc++.h>

using namespace std;

void PreOrder(int *arr) {}
void Order(int *arr)
{
}
void Merge(int *t1, int *t2, int maxsize)
{
    // maxsize为:两个树中的最大深度*2
    for (int i = 1; i <= maxsize; i++)
    {
        t1[i] += t2[i];
    }
}
// 第一行是前序遍历，第二行是中序遍历
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int tree1[220];
        int tree2[220];
        int n;
        cin >> n;
        bool lflag = false, rflag = false;
        int x, l, r;
        // 根节点无需判断
        cin >> x >> l >> r;
        tree1[1] = x;
        if (l)
            lflag = 1;
        if (r)
            rflag = 1;
        for (int i = 2; i <= n; i++)
        {

            cin >> x >> l >> r;
            if (lflag)
            {
                tree1[2 * i] = x;
                lflag = false;
            }
            if (rflag)
            {
                tree1[2 * i + 1] = x;
                rflag = false;
            }
            // 直接到下一层
            if (lflag || rflag)
                i = (i + 1) * 2;
            if (!lflag && !rflag)
                tree1[i] = x;
            // l r 不为空时,下次则直接输入它的左或右孩子
            if (l)
                lflag = 1;
            if (r)
                rflag = 1;
        }
        // 第二棵建树
        int n;
        cin >> n;
        bool lflag = false, rflag = false;
        int x, l, r;
        // 根节点无需判断
        cin >> x >> l >> r;
        tree2[1] = x;
        if (l)
            lflag = 1;
        if (r)
            rflag = 1;
        for (int i = 2; i <= n; i++)
        {

            cin >> x >> l >> r;
            if (lflag)
            {
                tree2[2 * i] = x;
                lflag = false;
            }
            if (rflag)
            {
                tree2[2 * i + 1] = x;
                rflag = false;
            }
            if (!lflag && !rflag)
                tree2[i] = x;
            // l r 不为空时,下次则直接输入它的左或右孩子
            if (l)
                lflag = 1;
            if (r)
                rflag = 1;
        }
    }
}