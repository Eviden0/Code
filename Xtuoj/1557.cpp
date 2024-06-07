#include <bits/stdc++.h>
using namespace std;

const int N = 20001;

int fa[N];
int sum;

int n, m;
struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const
    {
        return w > W.w;
    }
} edge[N];

int find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}

void kruskal()
{
    sort(edge + 1, edge + 1 + m);
    int res = 0, cnt = 0; // res权值之和，cnt经过的点数
    for (int i = 1; i <= m; i++)
    {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            fa[a] = b;
            res += w;
            cnt++;
        }
    }
    // cout << sum <<" "<<res << endl;
    cout << sum - res << endl;
    // 保证图是连通的
    // if(cnt<n-1)
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        sum = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            edge[i] = {a, b, w};
            sum += w;
        }
        kruskal();
    }
    return 0;
}