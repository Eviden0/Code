// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// // 定义二叉树节点结构体
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// // 计算每个节点的层大小并输出
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
//     // 创建二叉树
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     root->right->left = new TreeNode(6);
//     root->right->right = new TreeNode(7);

//     // 输出每个节点的层大小
//     layerSize(root);

//     return 0;
// }

#include <iostream>
using namespace std;
int values1[1000] = {0, 0};
int children1[1000] = {0, 0};
int values2[1000] = {0, 0};
int children2[1000] = {0, 0};
typedef struct Tree
{
    int data;
    Tree *left;
    Tree *right;
} Tree;
void Pre_tree(Tree *tree3, int *isFirst)
{ // 先序遍历
    if (NULL == tree3)
        return;
    if (*isFirst)
    {
        printf("%d", tree3->data);
        *isFirst = 0;
    }
    else
    {
        printf(" %d", tree3->data);
    }
    Pre_tree(tree3->left, isFirst);
    Pre_tree(tree3->right, isFirst);
}
void Med_tree(Tree *tree3, int *isFirst)
{ // 中序遍历
    if (tree3 == NULL)
        return;
    Med_tree(tree3->left, isFirst);
    if (*isFirst)
    {
        printf("%d", tree3->data);
        *isFirst = 0;
    }
    else
    {
        printf(" %d", tree3->data);
    }
    Med_tree(tree3->right, isFirst);
}
Tree *mergeTrees(Tree *t1, Tree *t2)
{
    if (!t1)
        return t2;
    if (!t2)
        return t1;
    Tree *newNode = new Tree;
    newNode->data = t1->data + t2->data;
    newNode->left = mergeTrees(t1->left, t2->left);
    newNode->right = mergeTrees(t1->right, t2->right);
    return newNode;
}
// void deleteTree(Tree* root) {
//     if (!root) return;
//     if(root->left) deleteTree(root->left);
//     if(root->right) deleteTree(root->right);
//     delete root;
// }
Tree *CreateTree(int n, int values[], int children[], int index)
{
    if (index <= 0)
        return NULL;
    if (index > n)
        return NULL;
    Tree *root = new Tree;
    root->data = values[index];
    if (children[index * 2] == 0)
        root->left = NULL;
    else
        root->left = CreateTree(n, values, children, children[index * 2]);
    if (children[index * 2 + 1] == 0)
        root->right = NULL;
    else
        root->right = CreateTree(n, values, children, children[index * 2 + 1]);
    return root;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n1, n2;
        scanf("%d", &n1);
        for (int i = 1; i <= n1; ++i)
        {
            scanf("%d %d %d", &values1[i], &children1[i * 2], &children1[i * 2 + 1]);
        }
        Tree *tree1 = CreateTree(n1, values1, children1, 1);
        scanf("%d", &n2);
        for (int i = 1; i <= n2; ++i)
        {
            scanf("%d %d %d", &values2[i], &children2[i * 2], &children2[i * 2 + 1]);
        }
        Tree *tree2 = CreateTree(n2, values2, children2, 1);
        Tree *tree3 = mergeTrees(tree1, tree2);
        int isFirst = 1;
        Pre_tree(tree3, &isFirst);
        printf("\n");
        isFirst = 1;
        Med_tree(tree3, &isFirst);
        printf("\n");
        //        deleteTree(tree1);
        //        deleteTree(tree2);
        //        deleteTree(tree3);
    }
    return 0;
}