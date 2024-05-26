#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int ans = 0;
        int warn = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                continue;
            }
            else
            {

                if (s[i] == s[i - 1])
                {
                    warn++;
                }
                else
                    warn = 0;
                if (warn >= 3)
                    continue;
                ans++;
            }
        }
        cout << ans << endl;
    }
}