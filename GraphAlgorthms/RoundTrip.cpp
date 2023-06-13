#include <bits/stdc++.h>

using namespace std;
bool dfs(vector<vector<int>> &graph, vector<int> &v, int crt, int p, vector<int> &temp)
{
    temp.push_back(crt + 1);
    v[crt] = 1;
    for (int i = 0; i < graph[crt].size(); i++)
    {
        if (v[graph[crt][i]])
        {
            if (graph[crt][i] != p)
            {
                temp.push_back(graph[crt][i] + 1);
                return true;
            }
        }
        else
        {
            if (dfs(graph, v, graph[crt][i], crt, temp))
                return true;
        }
    }
    temp.pop_back();
    return false;
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
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> v(n, 0);
    bool ok = false;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            vector<int> temp;
            if (dfs(graph, v, i, -1, temp))
            {
                ok = true;
                ans = temp;
                break;
            }
        }
    }
    if (ok)
    {
        map<int, int> mp;
        int start, end;
        for (int i = 0; i < ans.size(); i++)
        {
            if (mp.count(ans[i]))
            {
                start = mp[ans[i]];
                end = i;
                break;
            }
            else
                mp[ans[i]] = i;
        }
        cout << end - start + 1 << endl;
        for (int i = start; i <= end; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}