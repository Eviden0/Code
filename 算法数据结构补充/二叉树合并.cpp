// #include <bits/stdc++.h>

// using namespace std;

// void PreOrder(int *arr) {}
// void Order(int *arr)
// {
// }
// void Merge(int *t1, int *t2, int maxsize)
// {
//     // maxsize为:两个树中的最大深度*2
//     for (int i = 1; i <= maxsize; i++)
//     {
//         t1[i] += t2[i];
//     }
// }
// // 第一行是前序遍历，第二行是中序遍历
// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int tree1[220];
//         int tree2[220];
//         int n;
//         cin >> n;
//         bool lflag = false, rflag = false;
//         int x, l, r;
//         // 根节点无需判断
//         cin >> x >> l >> r;
//         tree1[1] = x;
//         if (l)
//             lflag = 1;
//         if (r)
//             rflag = 1;
//         for (int i = 2; i <= n; i++)
//         {

//             cin >> x >> l >> r;
//             if (lflag)
//             {
//                 tree1[2 * i] = x;
//                 lflag = false;
//             }
//             if (rflag)
//             {
//                 tree1[2 * i + 1] = x;
//                 rflag = false;
//             }
//             // 直接到下一层
//             if (lflag || rflag)
//                 i = (i + 1) * 2;
//             if (!lflag && !rflag)
//                 tree1[i] = x;
//             // l r 不为空时,下次则直接输入它的左或右孩子
//             if (l)
//                 lflag = 1;
//             if (r)
//                 rflag = 1;
//         }
//         // 第二棵建树
//         int n;
//         cin >> n;
//         bool lflag = false, rflag = false;
//         int x, l, r;
//         // 根节点无需判断
//         cin >> x >> l >> r;
//         tree2[1] = x;
//         if (l)
//             lflag = 1;
//         if (r)
//             rflag = 1;
//         for (int i = 2; i <= n; i++)
//         {

//             cin >> x >> l >> r;
//             if (lflag)
//             {
//                 tree2[2 * i] = x;
//                 lflag = false;
//             }
//             if (rflag)
//             {
//                 tree2[2 * i + 1] = x;
//                 rflag = false;
//             }
//             if (!lflag && !rflag)
//                 tree2[i] = x;
//             // l r 不为空时,下次则直接输入它的左或右孩子
//             if (l)
//                 lflag = 1;
//             if (r)
//                 rflag = 1;
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int n = 0;
struct TreeNode
{
    /* data */
    int data;
    TreeNode *l, *r;
    TreeNode(int x) //// 缺省参数写法
    {
        data = x;
        l = nullptr;
        r = nullptr;
    }
    TreeNode *creat()
    {
        // TreeNode *node = new TreeNode(3);
        // 建树有问题喔
        int val;
        cin >> val;
        int ll, rr;
        cin >> ll >> rr;
        if (val == -1)
            return nullptr;
        TreeNode *root = new TreeNode(val);
        if (ll)
            root->l = creat();
        else
            root->l = creat(0);
        if (rr)
            root->r = creat();
        else
            root->r = creat(0);
        n--;
        if (n <= 0)
            return root;
        return root;
    }
    TreeNode *creat(int x)
    {
        TreeNode *root = new TreeNode(x); // 缺省参数
        // l = nullptr;
        // r = nullptr;
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
void midOrder(TreeNode *T)
{
    if (T == nullptr)
        return;
    PreOrder(T->l);
    cout << T->data << ' ';
    PreOrder(T->r);
}
TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
{
    if (t1 == nullptr)
        return t2;
    if (t2 == nullptr)
        return t1;
    TreeNode *t3 = new TreeNode(t1->data + t2->data);
    t3->l = mergeTrees(t1->l, t2->l);
    t3->r = mergeTrees(t1->r, t2->r);
    return t3;
}
int main()
{
    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;
    cin >> n;
    root1 = root1->creat();
    cout << '\n'
         << "先序遍历1" << endl;
    PreOrder(root1);
    cin >> n;
    root2 = root2->creat();
    cout << '\n'
         << "先序遍历2" << endl;
    PreOrder(root2);
    TreeNode *t3 = mergeTrees(root1, root2);
    cout << '\n'
         << "先序遍历3" << endl;
    midOrder(root2);
}