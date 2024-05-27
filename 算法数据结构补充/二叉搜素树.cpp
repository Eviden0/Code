// #include <iostream>
// using namespace std;

// // 定义二叉树节点结构体
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// // 插入节点函数
// TreeNode *insert(TreeNode *root, int val)
// {
//     if (root == nullptr)
//     {
//         return new TreeNode(val);
//     }
//     if (val < root->val)
//     {
//         root->left = insert(root->left, val);
//     }
//     else if (val > root->val)
//     {
//         root->right = insert(root->right, val);
//     }
//     return root;
// }

// // 中序遍历打印二叉搜索树
// void inorderTraversal(TreeNode *root)
// {
//     if (root == nullptr)
//         return;
//     inorderTraversal(root->left);
//     cout << root->val << " ";
//     inorderTraversal(root->right);
// }
// void layerSize(TreeNode *root)
// {
//     if (root == nullptr)
//         return;

//     queue<TreeNode *> q;
//     q.push(root);
//     int level = 1;        // 记录当前节点的层号
//     int nodesInLevel = 0; // 记录当前层的节点数

//     while (!q.empty())
//     {
//         int size = q.size(); // 当前层的节点数
//         nodesInLevel = size;

//         cout << "Level " << level << ": ";
//         while (size--)
//         {
//             TreeNode *node = q.front();
//             q.pop();
//             cout << node->val << " ";

//             if (node->left != nullptr)
//                 q.push(node->left);
//             if (node->right != nullptr)
//                 q.push(node->right);
//         }
//         cout << "(Size: " << nodesInLevel << ")" << endl;

//         level++;
//     }
// }

// int main()
// {
//     // 创建空的二叉搜索树
//     TreeNode *root = nullptr;

//     // 插入节点

//     root = insert(root, 4);
//     root = insert(root, 7);
//     root = insert(root, 9);
//     root = insert(root, 5);
//     root = insert(root, 3);
//     root = insert(root, 8);
//     root = insert(root, 2);

//     // 中序遍历打印二叉搜索树（结果应该是有序的）
//     cout << "Inorder Traversal: ";
//     inorderTraversal(root);
//     cout << endl;

//     return 0;
// }
// #include <iostream>
// #include <vector>

// using namespace std;

// // 中序遍历函数
// void midorderTraversal(vector<int> &tree, int index)
// {
//     // if (index < tree.size() && tree[index] != 0)
//     // {
//     //     midorderTraversal(tree, 2 * index);     // 递归遍历左子树
//     //     cout << tree[index] << " ";             // 访问根节点
//     //     midorderTraversal(tree, 2 * index + 1); // 递归遍历右子树
//     // }
//     int l = 2 * index + 1;
//     int r = 2 * index + 2;
//     if (l < tree.size())
//         midorderTraversal(tree, l);
//     if (index < tree.size() && tree[index])
//         cout << tree[index] << ' ';
//     if (r < tree.size())
//         midorderTraversal(tree, r);

//     return;
// }

// int main()
// {
//     // 构造二叉树数组表示
//     vector<int> treeArray = {0, 4, 4, 0, 6, 2, 4};

//     // 执行中序遍历
//     cout << "中序遍历结果：";
//     midorderTraversal(treeArray, 0); // 从根节点开始遍历

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n2;
int n;
void preorderTraversal(vector<int> &tree, int index)
{
    int l = 2 * index;
    int r = 2 * index + 1;
    // index < tree.size() &&
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
    int r = 2 * index + 1;
    if (l < tree.size())
        midorderTraversal(tree, l);
    // index < tree.size() &&
    if (tree[index])
        cout << tree[index] << ' ';
    if (r < tree.size())
        midorderTraversal(tree, r);
}
int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        queue<int> qu1;
        qu1.push(1);
        vector<int> treeArry1(2200, 0);
        for (int i = 1; i <= n; i++)
        {
            int var, ll, rr;
            cin >> var >> ll >> rr;
            int index = qu1.front();
            treeArry1[index] = var;
            qu1.pop();
            if (ll)
                qu1.push(2 * index);
            if (rr)
                qu1.push(2 * index + 1);
        }

        cin >> n2;
        queue<int> qu2;
        qu2.push(1);
        vector<int> treeArry2(2200, 0);
        for (int i = 1; i <= n2; i++)
        {
            // 应该用的是上一次的值
            int var, ll, rr;
            cin >> var >> ll >> rr;
            int index = qu2.front();
            treeArry2[index] = var;
            qu2.pop();
            if (ll)
                qu2.push(2 * index);
            if (rr)
                qu2.push(2 * index + 1);
        }

        // preorderTraversal(treeArry1, 1);
        // cout << endl;
        // preorderTraversal(treeArry2, 1);
        // cout << endl;

        if (n2 > n)
        {
            // 用Arr2大一些
            for (int i = 1; i <= 2 * n + 1; i++)
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
            for (int i = 1; i <= 2 * n2 + 1; i++)
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