#include <bits/stdc++.h>
using namespace std;
void replace0(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            s.erase(i, 1);
            i--;
        }
    }
}
bool isDelete(string s, int index, int k)
{
    // 探测k范围内有无比它小的存在,有就直接删除该字符
    for (int i = index + 1; i <= index + k; i++)
    {
        if (s[i] < s[index])
            return true;
    }
    return false;
}
int main()
{
    // 50074897==>574897
    // k==3   74897 -- k==2 --4897--k==1  487
    // 去0
    int k;
    string a;
    cin >> a;
    cin >> k;
    int i;
    while (k)
    {
        for (i = 0; a[i] <= a[i + 1]; i++)
            ;
        a.erase(i, 1);
        k--;
    }
    while (a[0] == '0' && a.size() > 1)
        a.erase(0, 1);
    cout << a;
}