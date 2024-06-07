// // #include <bits/stdc++.h>
// // using namespace std;
// // int n, m, t;
// // int main()
// // {
// //     cin >> t;
// //     while (t--)
// //     {
// //         scanf("%d %d", &n, &m);
// //     }
// // }

// #include <stdio.h>
// #include <string.h>

// #define MAXN 205
// int dist[MAXN][MAXN];

// int main()
// {
//     int test_cases;
//     scanf("%d", &test_cases);

//     while (test_cases--)
//     {
//         int n, m;
//         scanf("%d %d", &n, &m);

//         // 初始化距离矩阵 dist，所有距离初始为 0
//         memset(dist, 0, sizeof(dist));

//         // 读取边的信息
//         for (int i = 0; i < m; ++i)
//         {
//             int x, y;
//             scanf("%d %d", &x, &y);
//             dist[y][x] = 1; // 表示从 y 到 x 有一条边
//         }

//         // 使用弗洛伊德算法计算传递闭包
//         for (int k = 1; k <= n; ++k)
//             for (int i = 1; i <= n; ++i)
//                 for (int j = 1; j <= n; ++j)
//                     dist[i][j] |= (dist[i][k] & dist[k][j]);

//         // 计算并输出每个顶点的 ans1 和 ans2
//         for (int i = 1; i <= n; ++i)
//         {
//             int reachable_count = 1, reachable_to_me_count = n;
//             for (int j = 1; j <= n; ++j)
//             {
//                 if (dist[i][j])
//                     ++reachable_count; // 统计能到达的点数
//                 if (dist[j][i])
//                     --reachable_to_me_count; // 统计可以到达自己的点数
//             }
//             printf("%d %d\n", reachable_count, reachable_to_me_count);
//         }
//         printf("\n"); // 在多个测试用例之间输出空行
//     }

//     return 0;
// }
#include <stdio.h>
#include <string.h>

#define MAXN 205
int dist[MAXN][MAXN];

// 初始化距离矩阵
void initialize_dist(int n)
{
    memset(dist, 0, sizeof(dist));
}

// 读取边的信息
void read_edges(int m)
{
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        dist[y][x] = 1; // 表示从 y 到 x 有一条边
    }
}

// 使用弗洛伊德算法计算传递闭包
void floyd_warshall(int n)
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] |= (dist[i][k] & dist[k][j]);
}

// 计算并输出每个顶点的可达性
void calculate_and_print_results(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        int reachable_count = 1, reachable_to_me_count = n;
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j])
                ++reachable_count; // 统计能到达的点数
            if (dist[j][i])
                --reachable_to_me_count; // 统计可以到达自己的点数
        }
        printf("%d %d\n", reachable_count, reachable_to_me_count);
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        initialize_dist(n);
        read_edges(m);
        floyd_warshall(n);
        calculate_and_print_results(n);

        if (t)
            printf("\n"); // 在多个测试用例之间输出空行
    }

    return 0;
}
