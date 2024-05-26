#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int value;
    Node *left, *right;
    Node(int x) : value(x), left(nullptr), right(nullptr) {}
    Node *creat()
    {
        int value;
        scanf("%d", &value);
        if (value == -1)
            return nullptr;
        Node *root = new Node(value);
        root->left = creat();

        root->right = creat();
        return root;
    }
    /* data */
};
int main()
{
}