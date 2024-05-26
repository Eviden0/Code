// #include <bits/stdc++.h>
// using namespace std;
// string ss[100010];
// int main()
// {
//     ios::sync_with_stdio(false);
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> ss[i];
//     string tar;
//     cin >> tar;
//     sort(ss, ss + n);
//     for (string i : ss)
//     {
//         if (i.find(tar) == 0)
//             cout << i << endl;
//     }
// }
// 小根堆,练习一下定义

#include <bits/stdc++.h>
using namespace std;
string ts, tar;
int n;
priority_queue<string, vector<string>, greater<string>> pq;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ts;
        pq.push(ts);
    }
    cin >> tar;
    for (int i = 0; i < n; i++)
    {
        ts = pq.top();
        if (ts.find(tar) == 0)
            cout << ts << endl;
        pq.pop();
    }
}