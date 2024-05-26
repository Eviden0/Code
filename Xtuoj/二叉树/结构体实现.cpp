#include <bits/stdc++.h>
using namespace std;
// https://www.cnblogs.com/linfangnan/p/12603112.html
struct Node
{
    char data;
    Node *lchild, *rchild;
    Node() = default;
    explicit Node(char data) : data(data)
    {
        lchild = nullptr;
        rchild = nullptr;
    }
    Node(char data, Node *left, Node *right) : data(data), lchild(left), rchild(right) {}
};

using BiTree = Node *; // 起别名

void create(BiTree &node)
{
    char ch;
    cin >> ch;
    if (ch == '0')
        return;
    if (ch == '#') // '#' => null character
        node = nullptr;
    else
    {
        node = new Node;
        node->data = ch;
        create(node->lchild); // 递归
        create(node->rchild);
    }
}

void preTraversal(BiTree root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preTraversal(root->lchild);
    preTraversal(root->rchild);
}
int main()
{
    BiTree T;
    cout << "Please input your tree node!" << endl;
    create(T);
    cout << "Created successfully!" << endl;
    cout << "===========Preorder traversal=========== " << endl;
    preTraversal(T);
}