#include <bits/stdc++.h>

using namespace std;

int dp[(int)(1e5) * 2 + 1];

int bfs(vector<vector<int>> &tree, int s)
{
    queue<int> q;
    vector<int> v(tree.size(), 0);
    vector<int> d(tree.size(), 0);
    d[s] = 0;
    q.push(s);
    int t;
    while (!q.empty())
    {
        t = q.front();
        v[t] = 1;
        q.pop();
        for (auto x : tree[t])
        {
            if (!v[x])
            {
                d[x] = d[t] + 1;
                dp[x] = max(dp[x], d[x]);
                q.push(x);
            }
        }
    }
    return t;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[--x].push_back(--y);
        tree[y].push_back(x);
    }
    memset(dp, 0, sizeof(dp));
    int e1 = bfs(tree, 0);
    int e2 = bfs(tree, e1);
    bfs(tree, e2);
    for (int i = 0; i < tree.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
}