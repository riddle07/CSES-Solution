#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<int> &v, int crt)
{
    v[crt] = 1;
    for (int i = 0; i < graph[crt].size(); i++)
    {
        if (!v[graph[crt][i]])
        {
            dfs(graph, v, graph[crt][i]);
        }
    }
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
    vector<int> first_val;
    int ans = 0;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            first_val.push_back(i + 1);
            dfs(graph, v, i);
            ans++;
        }
    }
    if (ans != 1)
    {
        cout << ans - 1 << endl;
        for (int i = 1; i < first_val.size(); i++)
        {
            cout << first_val[i - 1] << " " << first_val[i] << endl;
        }
    }
    else
        cout << "0" << endl;
}