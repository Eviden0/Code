// #include <stdio.h>
// int main()
// {
//     int t;
//     scanf("%d", &t);

//     while (t--)
//     {
//         int f = 1;
//         /* code */
//         int n;
//         scanf("%d", &n);
//         int l = 0, r = 0; // 维护左右重量
//         while (n--)
//         {
//             int a;
//             scanf("%d", &a);
//             if (r - l >= a - 1)
//                 r += a;
//             else
//             {
//                 f = 0;
//                 printf("%d\n", r + 1);
//                 break;
//             }
//         }
//         if (f)
//             printf("%d\n", r + 1);
//     }
// }

#include <stdio.h>

// 函数声明
int findSmallestNonrepresentableSum(int nums[], int size);

// 主函数
int main()
{
    int nums1[] = {1, 2, 4, 5, 6};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("无法表示的最小正整数: %d\n", findSmallestNonrepresentableSum(nums1, size1)); // 输出: 8

    int nums2[] = {1, 4, 5};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("无法表示的最小正整数: %d\n", findSmallestNonrepresentableSum(nums2, size2)); // 输出: 1

    return 0;
}

// 查找无法表示的最小正整数
int findSmallestNonrepresentableSum(int nums[], int size)
{
    int target_sum = 1;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] <= target_sum)
        {
            target_sum += nums[i];
        }
        else
        {
            break;
        }
    }

    return target_sum;
}
