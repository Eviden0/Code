#include <bits/stdc++.h>
using namespace std;

// 自定义结构体，用于保存元素和它的索引
struct IndexedElement
{
    int value;
    int index;
};

// 自定义比较函数，用于排序时比较元素的值
bool compare(const IndexedElement &a, const IndexedElement &b)
{
    return a.value < b.value; // 按照元素的值进行升序排序
}

void stable_sort_with_indices(std::vector<int> arr)
{
    int n = arr.size();
    // 创建一个结构体数组，保存元素和它的索引
    std::vector<IndexedElement> indexed_arr(n);
    for (int i = 0; i < n; ++i)
    {
        indexed_arr[i].value = arr[i];
        indexed_arr[i].index = i;
    }
    // 使用稳定排序算法对结构体数组进行排序
    std::stable_sort(indexed_arr.begin(), indexed_arr.end(), compare);
    // 输出排序之前的索引
    for (const auto &element : indexed_arr)
    {
        std::cout << element.index + 1 << " ";
    }
    std::cout << std::endl;
}
int main()
{
    int t;
    cin >> t;
    // 平均等待时间最短
    // 短作业优先呗!
    vector<int> a(t);
    // unordered_map<int, int> sonum;
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
        // 还会区分重复
        // if (!sonum[a[i]])
        //     sonum[a[i]] = i;
        // else {
        //     int tm = a[i];
        //     a[i] = -1;
        //     sonum
        // }
    }
    stable_sort_with_indices(a);
    sort(a.begin(), a.end());
    // 输出排列顺序
    double ans = 0;
    // for (int i : a)
    //     cout << i << ' ';
    // cout << sonum[a[0]] + 1;
    for (int i = 1; i < t; i++)
    {
        // cout << ' ' << sonum[a[i]] + 1;
        ans += (t - i) * a[i - 1];
    }
    // cout << endl;
    cout << fixed << setprecision(2) << ans / t;
}