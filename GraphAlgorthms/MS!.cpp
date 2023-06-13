#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>> &tree, int crt, vector<int> &v)
{
    v[crt] = 1;
    if (tree[crt].size() == 1 && crt != 0)
    {
        return 1;
    }
    int ans = 0;
    for (auto x : tree[crt])
    {
        if (!v[x])
        {
            ans += dfs(tree, x, v);
        }
    }
    if (crt == 0)
        return ans;
    return ans + (ans + 5) / 5;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    vector<int> v(n + 1, 0);
    cout << dfs(tree, 0, v) << endl;
}