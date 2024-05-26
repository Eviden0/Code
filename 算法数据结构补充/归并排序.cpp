#include <bits/stdc++.h>
using namespace std;

// 归并
void Merge(int arr[], int l, int m, int r)
{
    // copy此次归并,数组长度
    vector<int> help_arr(r - l + 1);
    // int *help_arr = new int[r - l + 1];
    // i是数组添加的标,a是归并左边的起始,b是归并右边的开始
    int i = 0, a = l, b = m + 1;
    while (a <= m && b <= r)
    {
        // 无越界
        help_arr[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while (a <= m)
        help_arr[i++] = arr[a++];
    while (b <= r)
        help_arr[i++] = arr[b++];

    // 从辅助空间拷贝回原数组
    for (int k = 0; k < r - l + 1; k++)
        arr[l + k] = help_arr[k];
    // delete[] help_arr;
}
// 递归版
void MergeSort(int arr[], int l, int r)
{
    if (l == r)
        return;
    int q = l + (r - l) / 2;
    MergeSort(arr, l, q);
    MergeSort(arr, q + 1, r);
    Merge(arr, l, q, r);
}
// 非递归版
void MergeSort2(int *arr, int n)
{
    // 每次合并step长的子数组
    for (int l, m, r, step = 1; step < n; step *= 2)
    {
        l = 0;
        while (l < n)
        {
            m = l + step - 1;
            if (m + 1 >= n)
                break;
            r = min(l + 2 * step - 1, n - 1);
            Merge(arr, l, m, r);
            l = r + 1;
        }
    }
}
int main()
{
    // 归并排序
    //  左部分排号序,右边排好序,在合并!
    int arr[5] = {3, 1, 2, 1, 0};
    // MergeSort(arr, 0, 4);
    MergeSort2(arr, 5);
    for (int i : arr)
        cout << i << ' ';
    // int a[8] = {3, 1, 2, 4, 5, 8, 7, 6};
    // MergSort(a, 0, 7);
    // for (int i = 0; i < 8; ++i)
    //     cout << a[i] << " ";
}