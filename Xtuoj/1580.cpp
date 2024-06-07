#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 10005
#define M 60005

struct edge
{
    int v, w, next;
};

struct dij
{
    int num;
    int len;
};

struct edge e[M];
int head[N], cnt;
int dis[N];
bool sym[N];

void add(int u, int v, int w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void swap(struct dij *a, struct dij *b)
{
    struct dij t = *a;
    *a = *b;
    *b = t;
}

void push(struct dij heap[], int *size, struct dij val)
{
    heap[++(*size)] = val;
    int now = *size;
    while (now > 1 && heap[now].len < heap[now / 2].len)
    {
        swap(&heap[now], &heap[now / 2]);
        now /= 2;
    }
}

void pop(struct dij heap[], int *size)
{
    heap[1] = heap[(*size)--];
    int now = 1;
    while (now * 2 <= *size)
    {
        int nxt = now * 2;
        if (nxt + 1 <= *size && heap[nxt + 1].len < heap[nxt].len)
            nxt++;
        if (heap[nxt].len >= heap[now].len)
            break;
        swap(&heap[now], &heap[nxt]);
        now = nxt;
    }
}

void dijkstra()
{
    struct dij heap[N];
    int size = 0;
    push(heap, &size, (struct dij){1, 0});
    while (size)
    {
        struct dij x = heap[1];
        pop(heap, &size);
        int u = x.num;
        if (sym[u])
            continue;
        sym[u] = true;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (!sym[v] && dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                push(heap, &size, (struct dij){v, dis[v]});
            }
        }
    }
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
    {
        dis[i] = INT_MAX;
    }
    for (int i = 1; i <= m; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    for (int i = 1; i <= k; ++i)
    {
        int x;
        scanf("%d", &x);
        dis[x] = 0;
    }

    dijkstra();

    for (int i = 1; i <= n; ++i)
    {
        printf("%d", dis[i]);
        if (i != n)
            printf(" ");
    }
    printf("\n");
    return 0;
}
