#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    /* data */
    int data;
    TreeNode *l, *r;
    TreeNode(int x = -1) //// 缺省参数写法
    {
        data = x;
        l = nullptr;
        r = nullptr;
    }
    TreeNode *creat()
    {
        // TreeNode *node = new TreeNode(3);
        int val;
        cin >> val;
        if (val == -1)
            return nullptr;
        TreeNode *root = new TreeNode(val);
        root->l = creat();
        root->r = creat();
        return root;
    }
    TreeNode *creat(int x)
    {
        TreeNode *root = new TreeNode(x); // 缺省参数
        root->l = creat();
        root->r = creat();
        return root;
    }
};
void PreOrder(TreeNode *T)
{
    if (T == nullptr)
        return;
    cout << T->data << ' ';
    PreOrder(T->l);
    PreOrder(T->r);
}

int main()
{
}