#include <bits/stdc++.h>

using namespace std;

int ans = INT_MIN;

int dfs(vector<vector<int>> &graph, int i, int j)
{
    if (graph[i].size() == 1)
        return 1;
    vector<int> temp;
    for (auto x : graph[i])
    {
        if (x != j)
        {
            temp.push_back(dfs(graph, x, i));
        }
    }
    sort(temp.begin(), temp.end(), greater<int>());
    if (temp.size() == 1)
    {
        ans = max({ans, 1 + temp[0], 1});
    }
    else
    {
        ans = max({ans, 1 + temp[0], 1 + temp[1], 1 + temp[0], temp[1], 1});
    }
    return max(1 + temp[0], 1);
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
    cout << ans << endl;
}