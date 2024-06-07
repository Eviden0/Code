/*
dp
dp[i][j]表示第i天是状态j时的最多训练天数
因此j对应5种状态
休息
一天篮
连续两天篮球
1天足球
连续两天足球
*/ \
#include<stdio.h>
#include <string.h>

#define MAX_LEN 10005 // 根据实际需求调整最大长度

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char s[MAX_LEN + 1];
        scanf("%s", s);
        int len = strlen(s);
        int ditui[len + 1][5];

        // 初始化数组
        memset(ditui, 0, sizeof(ditui));

        switch (s[0])
        {
        case '1':
            ditui[0][1] = 1;
            break;
        case '2':
            ditui[0][3] = 1;
            break;
        case '3':
            ditui[0][1] = 1;
            ditui[0][3] = 1;
            break;
        default:
            break;
        }

        for (int i = 1; i < len; i++)
        {
            ditui[i][0] = max(max(max(max(ditui[i - 1][0], ditui[i - 1][1]), ditui[i - 1][2]), ditui[i - 1][3]), ditui[i - 1][4]);

            if (s[i] == '1' || s[i] == '3')
            {
                ditui[i][1] = max(max(ditui[i - 1][0], ditui[i - 1][3]), ditui[i - 1][4]) + 1;
                ditui[i][2] = ditui[i - 1][1] + 1;
            }
            if (s[i] == '2' || s[i] == '3')
            {
                ditui[i][3] = max(max(ditui[i - 1][0], ditui[i - 1][1]), ditui[i - 1][2]) + 1;
                ditui[i][4] = ditui[i - 1][3] + 1;
            }
        }

        printf("%d\n", max(max(max(max(ditui[len - 1][0], ditui[len - 1][1]), ditui[len - 1][2]), ditui[len - 1][3]), ditui[len - 1][4]));
    }
    return 0;
}
