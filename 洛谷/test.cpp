#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> arr;
unordered_map<int, bool> vis;
void dfs(int x)
{
	if (arr.size() == n)
	{
		for (int i : arr)
			cout << i << ' ';
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;
		vis[i] = true;
		arr.push_back(i);
		dfs(i);
		vis[i] = false;
		arr.erase(arr.end() - 1);
	}
}

int main()
{

	// 输出1-n的全排列

	cin >> n;
	dfs(1);
}