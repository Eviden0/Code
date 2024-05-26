#include <bits/stdc++.h>
using namespace std;
int fin_left(int *arr, int size, int tar)
{
    // 找大于等于目标值的最左边界
    int l = 0, r = size - 1;
    int ans = -1; // 找不到默认返回-1
    while (l <= r)
    {
        int m = l + ((r - l) >> 1);
        // m=l+(r-l)/2  最朴素的理解,加上l r 的距离求一半
        //  int m = (l + r) / 2;
        if (arr[m] >= tar)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}
int find_right(int *arr, int size, int tar)
{
    // 找小于等于的最右位置
    int l = 0, r = size - 1, m, ans = -1;
    while (l <= r)
    {
        m = l + ((r - l) >> 1);
        if (arr[m] <= tar)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}
void prin_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
}
int main()
{
    int arr[] = {4, 3, 12, 22, 33, 9, 2, 1, 22};
    int size = sizeof(arr) / arr[0];
    sort(arr, arr + size);
    prin_arr(arr, size);
    cout << endl;

    cout << ":: " << fin_left(arr, size, 22) << endl;
    cout << ":: " << find_right(arr, size, 22);
    // printf(fin_left(arr,sizeof(arr),))
}