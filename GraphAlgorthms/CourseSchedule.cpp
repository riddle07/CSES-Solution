#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> id(n, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        id[y]++;
    }
    queue<int> q;
    for (int i = 0; i < id.size(); i++)
    {
        if (!id[i])
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int crt = q.front();
        ans.push_back(crt);
        q.pop();
        for (auto x : graph[crt])
        {
            if (id[x])
            {
                id[x]--;
            }
            if (!id[x])
            {
                q.push(x);
            }
        }
    }
    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (auto x : ans)
        {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}