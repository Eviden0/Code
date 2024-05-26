#include <bits/stdc++.h>

using namespace std;
void Merge(int *arr, int l, int m, int r)
{
    int a = l, b = m + 1;
    int size = r - l + 1;
    int i = 0;
    vector<int> help(size);
    while (a <= m && b <= r)
    {
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while (a <= m)
    {
        help[i++] = arr[a++];
    }
    while (b <= r)
    {
        help[i++] = arr[b++];
    }
    for (int k = 0; k < size; k++)
    {
        arr[k + l] = help[k];
    }
}
void MergeSort(int *arr, int l, int r)
{
    if (l == r)
        return;
    int m = l + (r - l) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);
    Merge(arr, l, m, r);
}

int main()
{
    int a[8] = {3, 1, 2, 4, 5, 8, 7, 6};
    MergeSort(a, 0, 7);
    for (int i = 0; i < 8; ++i)
        cout << a[i] << " ";
}