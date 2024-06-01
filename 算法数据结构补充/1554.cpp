#include <stdio.h>
#include <string.h>

#define MAX_NODES 2000

struct TreeNode
{
    int left_child;
    int right_child;
    int depth;
};

int node_map[MAX_NODES][3];
int depths[MAX_NODES];
int node_values[MAX_NODES];
int node_count;

void insert_to_tree(int parent_index, int value)
{
    if (value > node_values[parent_index])
    {
        if (node_map[parent_index][1] > 0)
            insert_to_tree(node_map[parent_index][1], value);
        else
        {
            node_values[node_count] = value;
            depths[node_count] = depths[parent_index] + 1;
            node_map[parent_index][1] = node_count;
            node_count++;
        }
    }
    else
    {
        if (node_map[parent_index][0] > 0)
            insert_to_tree(node_map[parent_index][0], value);
        else
        {
            node_values[node_count] = value;
            depths[node_count] = depths[parent_index] + 1;
            node_map[parent_index][0] = node_count;
            node_count++;
        }
    }
}

int calculate_depth_sum()
{
    int sum = 0;
    for (int i = 1; i < node_count; i++)
        sum += depths[i];
    return sum;
}

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--)
    {
        int n;
        scanf("%d", &n);
        int values[MAX_NODES];
        memset(depths, 0, sizeof(depths));
        memset(node_values, 0, sizeof(node_values));
        for (int i = 0; i < n; i++)
            scanf("%d", &values[i]);
        for (int i = 0; i <= n + 10; i++)
        {
            node_map[i][0] = 0;
            node_map[i][1] = 0;
            node_map[i][2] = 0;
        }
        node_count = 1;
        node_values[node_count] = values[0];
        depths[node_count] = 1;
        node_count++;
        for (int i = 1; i < n; i++)
            insert_to_tree(1, values[i]);
        printf("%d\n", calculate_depth_sum());
    }
    return 0;
}
