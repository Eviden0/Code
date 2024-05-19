// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
char a[4];
// string a;
vector<int> pq;
int main()
{
    // int n1=3;
    pq.push_back(0);
    // int index = 0;
    while (scanf("%s", a) != EOF)
    {
        int index;
        if (a[1] == 'u')
        {
            int n;
            scanf("%d", &n);
            index = lower_bound(pq.begin(), pq.end(), n) - pq.begin();

            // cout<<index<<endl;

            pq.insert(pq.begin() + index, n);
            // index++;
        }
        else
        {
            // for (int i : pq)
            //     cout << i << ' ';
            // cout << endl;
            int dl = (pq.size()) / 2;
            // cout << pq[dl] << endl;
            printf("%d\n", pq[dl]);
            pq.erase(pq.begin() + dl);
        }
    }
}