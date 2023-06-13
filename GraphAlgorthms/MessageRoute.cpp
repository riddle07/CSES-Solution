#include <bits/stdc++.h>

using namespace std;

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
    vector<int> d(n, INT_MAX);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> parent(n, -1);
    pq.push(make_pair(0, 0));
    while (!pq.empty())
    {
        int crt_node = pq.top().second;
        int crt_d = pq.top().first;
        pq.pop();
        for (auto x : graph[crt_node])
        {
            if (d[x] > crt_d + 1)
            {
                d[x] = crt_d + 1;
                parent[x] = crt_node;
                pq.push(make_pair(d[x], x));
            }
        }
    }
    if (d[n - 1] == INT_MAX)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << d[n - 1] + 1 << endl;
        vector<int> path;
        int x = n - 1;
        while (x != -1)
        {
            path.push_back(x + 1);
            x = parent[x];
        }
        reverse(path.begin(), path.end());
        for (auto y : path)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}