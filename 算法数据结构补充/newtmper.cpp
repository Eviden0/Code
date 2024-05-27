#include <bits/stdc++.h>
using namespace std;

void preorderTraversal(vector<int> &tree, int index)
{
    int l = 2 * index;
    int r = 2 * index + 1;
    if (tree[index])
        cout << tree[index] << ' ';
    if (l < tree.size())
        preorderTraversal(tree, l);

    if (r < tree.size())
        preorderTraversal(tree, r);
}

void midorderTraversal(vector<int> &tree, int index)
{

    int l = 2 * index;
    if (l < tree.size())
        midorderTraversal(tree, l);
    if (tree[index])
        cout << tree[index] << ' ';
    int r = 2 * index + 1;
    if (r < tree.size())
        midorderTraversal(tree, r);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<int> qu1;
        qu1.push(1);
        vector<int> treeArry1(220, 0);
        for (int i = 1; i <= n; i++)
        {
            int var, ll, rr;
            cin >> var >> ll >> rr;
            treeArry1[qu1.front()] = var;
            qu1.pop();
            if (ll)
                qu1.push(2 * i);
            if (rr)
                qu1.push(2 * i + 1);
        }
        int n2;
        cin >> n2;
        queue<int> qu2;
        qu2.push(1);
        vector<int> treeArry2(210, 0);
        for (int i = 1; i <= n2; i++)
        {
            // 应该用的是上一次的值
            int var, ll, rr;
            cin >> var >> ll >> rr;
            treeArry2[qu2.front()] = var;
            qu2.pop();
            if (ll)
                qu2.push(2 * i);
            if (rr)
                qu2.push(2 * i + 1);
        }

        preorderTraversal(treeArry2, 1);
        cout << endl;
        if (n2 > n)
        {
            // 用Arr2大一些
            for (int i = 1; i <= 2 * n; i++)
            {
                treeArry2[i] += treeArry1[i];
            }
            // for (int i : treeArry2)
            //     cout << i << ' ';
            // cout << endl;
            preorderTraversal(treeArry2, 1);
            cout << endl;
            midorderTraversal(treeArry2, 1);
            cout << endl;
        }
        else
        {
            for (int i = 1; i <= 2 * n2; i++)
            {
                treeArry1[i] += treeArry2[i];
            }
            // for (int i : treeArry1)
            //     cout << i << ' ';
            // cout << endl;
            preorderTraversal(treeArry1, 1);
            cout << endl;
            midorderTraversal(treeArry1, 1);
            cout << endl;
        }
    }
}