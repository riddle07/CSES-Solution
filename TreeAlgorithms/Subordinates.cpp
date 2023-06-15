#include <bits/stdc++.h>

using namespace std;

int sub[2 * (int)(1e5) + 1];

int dfs(vector<vector<int>> &graph, int i)
{
    if (graph[i].size() == 0)
    {
        sub[i] = 0;
        return 0;
    }
    for (auto x : graph[i])
    {
        sub[i] += 1 + dfs(graph, x);
    }
    return sub[i];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> v[i];
    vector<vector<int>> graph(n);
    for (int i = 0; i < v.size(); i++)
    {
        graph[v[i] - 1].push_back(i + 1);
    }
    dfs(graph, 0);
    for (int i = 0; i < n; i++)
        cout << sub[i] << " ";
    cout << endl;
}