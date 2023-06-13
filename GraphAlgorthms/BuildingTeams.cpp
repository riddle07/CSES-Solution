#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &graph, int i, vector<int> &visited, int p)
{
    visited[i] = p;
    bool ok = true;
    for (auto x : graph[i])
    {
        if (!visited[x])
            ok = ok && dfs(graph, x, visited, (p % 2 + 1));
        else if (visited[x] == p)
            return false;
    }
    return ok;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }
    vector<int> visited(n, 0);
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            ok = ok && dfs(graph, i, visited, 1);
        if (!ok)
            break;
    }
    if (ok)
    {
        for (auto x : visited)
            cout << x << " ";
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}