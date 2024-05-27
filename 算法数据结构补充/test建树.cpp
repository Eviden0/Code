#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 定义二叉树节点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 构建二叉树函数
TreeNode *buildTree(vector<vector<int>> &nodes)
{
    unordered_map<int, TreeNode *> nodeMap;

    // 创建根节点
    TreeNode *root = new TreeNode(nodes[0][0]);
    nodeMap[nodes[0][0]] = root;

    // 遍历节点信息，构建二叉树
    for (auto &nodeInfo : nodes)
    {
        int parentVal = nodeInfo[0];
        int leftVal = nodeInfo[1];
        int rightVal = nodeInfo[2];

        TreeNode *parent = nodeMap[parentVal];
        if (leftVal != 0)
        {
            parent->left = new TreeNode(leftVal);
            nodeMap[leftVal] = parent->left;
        }
        if (rightVal != 0)
        {
            parent->right = new TreeNode(rightVal);
            nodeMap[rightVal] = parent->right;
        }
    }

    return root;
}

// 先序遍历打印二叉树
void printTree(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    vector<vector<int>> nodes = {{1, 2, 3}, {2, 4, 0}, {5, 0, 0}, {4, 0, 0}};

    TreeNode *root = buildTree(nodes);

    printTree(root);

    return 0;
}
