#include <stdio.h>

int t[2000001];
int maxindex;
void insert(int x, int next)
{
    // 递归插入
    if (x < t[next])
    {
        // 左侧插入
        if (t[next * 2] == 0)
        {
            t[next * 2] = x;

            // next = next * 2;
            maxindex = maxindex > next * 2 ? maxindex : next * 2;
        }
        else
        {
            insert(x, next * 2);
        }
    }
    else
    {
        // 右侧插入
        if (t[next * 2 + 1] == 0)
        {
            t[next * 2 + 1] = x;
            // next = next * 2 + 1;
            maxindex = maxindex > next * 2 + 1 ? maxindex : next * 2 + 1;
        }
        else
        {
            insert(x, next * 2 + 1);
        }
    }
}
int main()
{
    int T;
    int n;
    scanf("%d", &T);
    while (T--)
    {

        scanf("%d", &n);
        int x;
        scanf("%d", &x);
        t[1] = x;

        // int next = 1;
        maxindex = 1;
        for (int i = 2; i <= n; i++)
        {
            scanf("%d", &x);
            insert(x, 1);
        }
        printf("%d\n", maxindex - n);
        // memset(t, 0, maxindex + 1);
        // 防止超时
        for (int i = 0; i <= maxindex + 1; i++)
        {
            t[i] = 0;
        }
    }
}