#include <stdio.h>

// 存储树的左孩子和右孩子的数组
int leftChild[3][305], rightChild[3][305];
// 存储树的节点值
int nodeValue[3][305], preOrderResult[305], inOrderResult[305];
int nodeCount, preOrderCount, inOrderCount;

// 合并两棵树的递归函数
int mergeTrees(int node1, int node2)
{
    int currentNode = ++nodeCount;
    nodeValue[2][currentNode] = nodeValue[0][node1] + nodeValue[1][node2];

    if (leftChild[0][node1] || leftChild[1][node2])
    {
        leftChild[2][currentNode] = mergeTrees(leftChild[0][node1], leftChild[1][node2]);
    }
    if (rightChild[0][node1] || rightChild[1][node2])
    {
        rightChild[2][currentNode] = mergeTrees(rightChild[0][node1], rightChild[1][node2]);
    }

    return currentNode;
}

// 前序遍历
void preOrderTraversal(int node)
{
    preOrderResult[++preOrderCount] = nodeValue[2][node];
    if (leftChild[2][node])
    {
        preOrderTraversal(leftChild[2][node]);
    }
    if (rightChild[2][node])
    {
        preOrderTraversal(rightChild[2][node]);
    }
}

// 中序遍历
void inOrderTraversal(int node)
{
    if (leftChild[2][node])
    {
        inOrderTraversal(leftChild[2][node]);
    }
    inOrderResult[++inOrderCount] = nodeValue[2][node];
    if (rightChild[2][node])
    {
        inOrderTraversal(rightChild[2][node]);
    }
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    while (testCases--)
    {
        int nodes;
        nodeCount = preOrderCount = inOrderCount = 0;

        // 初始化数组
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 305; j++)
            {
                leftChild[i][j] = 0;
                rightChild[i][j] = 0;
                nodeValue[i][j] = 0;
            }
        }

        for (int treeIndex = 0; treeIndex <= 1; treeIndex++)
        {
            scanf("%d", &nodes);

            for (int i = 1; i <= nodes; i++)
            {
                scanf("%d%d%d", &nodeValue[treeIndex][i], &leftChild[treeIndex][i], &rightChild[treeIndex][i]);
            }
        }

        mergeTrees(1, 1);
        preOrderTraversal(1);
        inOrderTraversal(1);

        printf("%d", preOrderResult[1]);
        for (int i = 2; i <= preOrderCount; i++)
        {
            printf(" %d", preOrderResult[i]);
        }
        printf("\n%d", inOrderResult[1]);
        for (int i = 2; i <= inOrderCount; i++)
        {
            printf(" %d", inOrderResult[i]);
        }
        printf("\n");
    }

    return 0;
}
