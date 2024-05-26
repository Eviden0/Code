#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left, *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
    TreeNode() : value(-1), left(nullptr), right(nullptr) {}
    TreeNode *creat()
    {
        int value;
        cin >> value;
        if (value == -1)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(value);
        root->left = creat();
        root->right = creat();
        return root;
    }
};
void preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    std::cout << root->value << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    // 创建二叉树
    TreeNode *root = nullptr;
    TreeNode *ro = new TreeNode();

    cout << "输入二叉树节点的值（-1表示空节点）：" << endl;
    // root = root->creat();
    ro = ro->creat();
    // 先序遍历二叉树
    cout << "先序遍历结果：" << endl;
    // preorderTraversal(root);
    preorderTraversal(ro);
    return 0;
}