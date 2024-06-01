// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 100005;
// struct node
// {
//     int l, r, cnt;
//     node()
//     {
//         l = r = -1;
//         cnt = 0;
//     }
// } huff[maxn << 3];
// int ans[maxn];
// int n;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     scanf("%d", &n);
//     int m, t, cnt = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         scanf("%d", &m);
//         t = 0;
//         while (m)
//         {
//             if (m & 1)
//             {
//                 if (huff[t].r == -1)
//                 {
//                     huff[t].r = ++cnt;
//                     t = cnt;
//                 }
//                 else
//                 {
//                     t = huff[t].r;
//                     ++(huff[t].cnt);
//                 }
//             }
//             else
//             {
//                 if (huff[t].l == -1)
//                 {
//                     huff[t].l = ++cnt;
//                     t = cnt;
//                 }
//                 else
//                 {
//                     t = huff[t].l;
//                     ++(huff[t].cnt);
//                 }
//             }
//             m >>= 1;
//         }
//         ans[i] = t;
//     }
//     for (int i = 0; i < n; ++i)
//         printf("%d\n", huff[ans[i]].cnt);
//     return 0;
// }

#include <stdio.h>

#define MAXN 100005
#define MAXNODES (MAXN << 3)

struct Node
{
    int l;
    int r;
    int cnt;
};

struct Node huff[MAXNODES];
int ans[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    int m, t, cnt = 0;

    // 初始化 huff 数组
    for (int i = 0; i < MAXNODES; ++i)
    {
        huff[i].l = -1;
        huff[i].r = -1;
        huff[i].cnt = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &m);
        t = 0;
        while (m)
        {
            if (m & 1)
            {
                if (huff[t].r == -1)
                {
                    huff[t].r = ++cnt;
                    t = cnt;
                }
                else
                {
                    t = huff[t].r;
                    ++huff[t].cnt;
                }
            }
            else
            {
                if (huff[t].l == -1)
                {
                    huff[t].l = ++cnt;
                    t = cnt;
                }
                else
                {
                    t = huff[t].l;
                    ++huff[t].cnt;
                }
            }
            m >>= 1;
        }
        ans[i] = t;
    }
    for (int i = 0; i < n; ++i)
        printf("%d\n", huff[ans[i]].cnt);
    return 0;
}
