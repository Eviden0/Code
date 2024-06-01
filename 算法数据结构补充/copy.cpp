#include <stdio.h>
#include <stdlib.h>

// 创建新节点
int *createNode(int val)
{
    int *newNode = (int *)malloc(3 * sizeof(int));
    newNode[0] = val;
    newNode[1] = -1; // left child
    newNode[2] = -1; // right child
    return newNode;
}

// 构建二叉树
int **buildTree(int n, int nodes[][3])
{
    int **tree = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; ++i)
    {
        tree[i] = createNode(nodes[i - 1][0]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (nodes[i - 1][1] != 0)
        {
            tree[i][1] = nodes[i - 1][1];
        }
        if (nodes[i - 1][2] != 0)
        {
            tree[i][2] = nodes[i - 1][2];
        }
    }
    return tree;
}

// 合并二叉树
int *mergeTrees(int **tree1, int **tree2, int t1_index, int t2_index)
{
    if (t1_index == -1)
        return tree2[t2_index];
    if (t2_index == -1)
        return tree1[t1_index];
    int *merged = createNode(tree1[t1_index][0] + tree2[t2_index][0]);
    merged[1] = mergeTrees(tree1, tree2, tree1[t1_index][1], tree2[t2_index][1]); // 合并左子树
    merged[2] = mergeTrees(tree1, tree2, tree1[t1_index][2], tree2[t2_index][2]); // 合并右子树
    return merged;
}

// 前序遍历
void preorder(int **tree, int root_index, int *first)
{
    if (root_index == -1)
        return;
    if (*first)
    {
        printf("%d", tree[root_index][0]);
        *first = 0;
    }
    else
    {
        printf(" %d", tree[root_index][0]);
    }
    preorder(tree, tree[root_index][1], first);
    preorder(tree, tree[root_index][2], first);
}

// 中序遍历
void inorder(int **tree, int root_index, int *first)
{
    if (root_index == -1)
        return;
    inorder(tree, tree[root_index][1], first);
    if (*first)
    {
        printf("%d", tree[root_index][0]);
        *first = 0;
    }
    else
    {
        printf(" %d", tree[root_index][0]);
    }
    inorder(tree, tree[root_index][2], first);
}

// 释放二叉树节点内存
void freeTree(int **tree, int root_index)
{
    if (root_index == -1)
        return;
    freeTree(tree, tree[root_index][1]);
    freeTree(tree, tree[root_index][2]);
    free(tree[root_index]);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n1, n2;
        scanf("%d", &n1);
        int nodes1[n1][3];
        for (int i = 0; i < n1; ++i)
        {
            scanf("%d %d %d", &nodes1[i][0], &nodes1[i][1], &nodes1[i][2]);
        }
        scanf("%d", &n2);
        int nodes2[n2][3];
        for (int i = 0; i < n2; ++i)
        {
            scanf("%d %d %d", &nodes2[i][0], &nodes2[i][1], &nodes2[i][2]);
        }

        int **tree1 = buildTree(n1, nodes1);
        int **tree2 = buildTree(n2, nodes2);

        int mergedTreeRoot = mergeTrees(tree1, tree2, 1, 1);

        int first = 1;
        preorder(tree1, mergedTreeRoot, &first);
        printf("\n");
        first = 1;
        inorder(tree1, mergedTreeRoot, &first);
        printf("\n");

        // 释放内存
        freeTree(tree1, mergedTreeRoot);
        freeTree(tree2, 1); // 根节点索引为1
        free(tree1);
        free(tree2);
    }
    return 0;
}
