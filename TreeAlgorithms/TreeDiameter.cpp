#include <bits/stdc++.h>

using namespace std;

int ans = INT_MIN;

int dfs(vector<vector<int>> &graph, int i, int j)
{
    vector<int> c;
    for (auto x : graph[i])
    {
        if (x != j)
        {
            c.push_back(dfs(graph, x, i));
        }
    }
    if (c.size() == 0)
    {
        ans = max(ans, 1);
        return 1;
    }
    else if (c.size() == 1)
    {
        ans = max({ans, 1, c[0] + 1});
        return c[0] + 1;
    }
    else
    {
        sort(c.begin(), c.end(), greater<int>());
        ans = max({ans, 1, c[0] + 1, c[1] + 1, c[0] + c[1] + 1});
        return 1 + max(c[0], c[1]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[--x].push_back(--y);
        graph[y].push_back(x);
    }
    dfs(graph, 0, -1);
    cout << ans - 1 << endl;
}